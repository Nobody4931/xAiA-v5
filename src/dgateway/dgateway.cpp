#define ASIO_STANDALONE

#include "dgateway/dgateway.hpp"

#include <cstdint>
#include <cstring>
#include <system_error>
#include <iostream>
#include <functional>
#include <chrono>
#include <regex>
#include <thread>
#include <vector>
#include <string>

#include <fmt/core.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <websocketpp/connection.hpp>
#include <websocketpp/http/parser.hpp>
#include <websocketpp/http/request.hpp>
#include <websocketpp/http/response.hpp>
#include <websocketpp/base64/base64.hpp>

#include "config.hpp"
#include "util/str2num.hpp"
#include "dapi/dapi.hpp"
#include "dcache/dtypes.hpp"

namespace http = websocketpp::http;


uint32_t get_client_build_number( asio::io_context& io_ctx, std::string& headers ) {
	static const std::regex asset_re( R"(assets\/([a-z0-9]+)\.js)", std::regex::ECMAScript | std::regex::optimize );

	// Get discord assets
	asio::streambuf request;
	std::ostream request_stream( &request );

	request_stream <<
		"GET /login HTTP/1.0\r\n"
		<< headers << "\r\n";

	http::parser::response login_page = dapi_request( io_ctx, request );
	const std::string& login_page_str = login_page.get_body();
	std::vector<std::string> dassets;

	std::sregex_iterator re_iter( login_page_str.cbegin(), login_page_str.cend(), asset_re );
	std::sregex_iterator re_end;

	while ( re_iter != re_end ) {
		dassets.push_back( re_iter->str( 1 ) );
		++re_iter;
	}

	// Get discord build number
	asio::streambuf brequest;
	std::ostream brequest_stream( &brequest );

	brequest_stream <<
		"GET /assets/" << dassets[ dassets.size() - 2 ] << ".js HTTP/1.0\r\n"
		<< headers << "\r\n";

	http::parser::response dasset = dapi_request( io_ctx, brequest );
	const std::string& dasset_str = dasset.get_body();

	return str_to_integer<uint32_t>( dasset_str.substr( dasset_str.find( "buildNumber" ) + 14, 5 ) );
}


void dclient_t::setup() {
	// TODO: Remove headers that aren't checked?
	m_base_headers =
		"Host: " CFG_DAPI_HOSTNAME "\r\n"
		"Origin: https://" CFG_DAPI_HOSTNAME "\r\n"
		"Referer: https://" CFG_DAPI_HOSTNAME "/channels/@me\r\n"
		"User-Agent: " CFG_DAPI_AGENT "\r\n"
		"Accept: */*\r\n"
		"Accept-Language: " CFG_DAPI_LOCALE "\r\n"
		"Authorization: " CFG_TOKEN "\r\n"
		"Cache-Control: no-cache\r\n"
		"Pragma: no-cache\r\n"
		"Sec-Fetch-Dest: empty\r\n"
		"Sec-Fetch-Mode: cors\r\n"
		"Sec-Fetch-Site: same-origin\r\n"
		"Connection: close\r\n";

	// Generate SuperProperties
	// SEE: https://luna.gitlab.io/discord-unofficial-docs/science.html#super-properties-object

#if CFG_DAPI_SPOOF_MOBILE == 0

	m_super_properties["os"] = CFG_DAPI_AGENT_OS;
	m_super_properties["browser"] = CFG_DAPI_AGENT_BROWSER;
	m_super_properties["device"] = "";
	m_super_properties["system_locale"] = CFG_DAPI_LOCALE;
	m_super_properties["browser_user_agent"] = CFG_DAPI_AGENT;
	m_super_properties["browser_version"] = CFG_DAPI_AGENT_BROWSER_VERSION;
	m_super_properties["os_version"] = CFG_DAPI_AGENT_OS_VERSION;
	m_super_properties["referrer"] = "";
	m_super_properties["referring_domain"] = "";
	m_super_properties["referrer_current"] = "";
	m_super_properties["referring_domain_current"] = "";
	m_super_properties["release_channel"] = "stable";
	m_super_properties["client_build_number"] = get_client_build_number( m_io_ctx, m_base_headers );
	m_super_properties["client_event_source"] = nullptr;

#else // CFG_DAPI_SPOOF_MOBILE != 0

	// NOTE: Update this whenever I update Discord on my phone aswell
	// * And the User Agent used aswell

	// yanked straight from my phone lol
	m_super_properties["os"] = "iOS";
	// m_super_properties["os"] = "14.7.1";                    // or is it here...
	m_super_properties["browser"] = "Discord iOS";
	m_super_properties["device"] = "iPhone12,1";
	m_super_properties["system_locale"] = CFG_DAPI_LOCALE;
	m_super_properties["os_version"] = "14.7.1";               // ...and not here?
	m_super_properties["referrer"] = "";
	m_super_properties["referring_domain"] = "";
	m_super_properties["referrer_current"] = "";
	m_super_properties["referring_domain_current"] = "";
	m_super_properties["release_channel"] = "stable";
	m_super_properties["client_build_number"] = 27527;
	m_super_properties["client_event_source"] = nullptr;

#endif // CFG_DAPI_SPOOF_MOBILE

	m_base_headers += "X-Super-Properties: ";
	m_base_headers += websocketpp::base64_encode( m_super_properties.dump() );
	m_base_headers += "\r\n";
}

void dclient_t::connect() {
	std::error_code err_code;
	client_t::connection_ptr con_ptr = m_client.get_connection( DGATE_ENDPOINT, err_code );

	if ( err_code ) {
		spdlog::error( "Unable to initialize connection: {}", err_code.message() );
		return;
	}

	con_ptr->set_close_handler( std::bind( &dclient_t::on_close, this,
		std::placeholders::_1 ) );
	con_ptr->set_message_handler( std::bind( &dclient_t::on_message, this,
		std::placeholders::_1, std::placeholders::_2 ) );

	spdlog::debug( "Connecting to gateway..." );
	m_client.connect( con_ptr );
}


void dclient_t::heartbeat( websocketpp::connection_hdl con_hdl ) {
	spdlog::trace( "Sending HEARTBEAT..." );

	if ( m_last_sequence == -1 ) {
		m_client.send( con_hdl, "{\"op\":1,\"d\":null}", websocketpp::frame::opcode::TEXT );
	} else {
		m_client.send( con_hdl, fmt::format( "{{\"op\":1,\"d\":{}}}", m_last_sequence ), websocketpp::frame::opcode::TEXT );
	}

	spdlog::trace( "Successfully sent HEARTBEAT" );
}

void dclient_t::heartbeat_loop( websocketpp::connection_hdl con_hdl ) {
	uint8_t current_id = m_heartbeat_id;
	while ( current_id == m_heartbeat_id ) {
		this->heartbeat( con_hdl );
		std::this_thread::sleep_for( m_heartbeat_interval );
	}
}

void dclient_t::identify( websocketpp::connection_hdl con_hdl ) {
	nlohmann::json payload;

	// Identify
	if ( m_last_sequence == -1 ) {
		payload["op"] = OP_IDENTIFY;
		payload["d"]["token"] = CFG_TOKEN;
		payload["d"]["capabilities"] = 125;
		payload["d"]["compress"] = false;
		payload["d"]["properties"] = m_super_properties;
		payload["d"]["client_state"]["guild_hashes"] = nlohmann::json::object();
		payload["d"]["client_state"]["highest_last_message_id"] = "0";
		payload["d"]["client_state"]["read_state_version"] = 0;
		payload["d"]["client_state"]["user_guild_settings_version"] = -1;
	}

	// Resume
	else {
		payload["op"] = OP_RESUME;
		payload["d"]["token"] = CFG_TOKEN;
		payload["d"]["session_id"] = m_session_id;
		payload["d"]["seq"] = m_last_sequence - 1;
	}

	spdlog::trace( "Sending IDENTIFY/RESUME..." );
	m_client.send( con_hdl, payload.dump(), websocketpp::frame::opcode::TEXT );
	spdlog::trace( "Successfully sent IDENTIFY/RESUME" );
}


void dclient_t::on_close( websocketpp::connection_hdl con_hdl ) {
	client_t::connection_ptr con_ptr = m_client.get_con_from_hdl( con_hdl );

	disc_gate_close_op_type close_code = static_cast<disc_gate_close_op_type>( con_ptr->get_remote_close_code() );

	spdlog::debug( "Disconnected from gateway: {} '{}'",
		close_code, con_ptr->get_remote_close_reason() );

	switch ( close_code ) {

		case CLOSE_OP_INVALID_SEQ:
		case CLOSE_OP_SESSION_TIMED_OUT:
			m_last_sequence = -1;
			m_session_id.clear();
			break;

		default:
			break;

	}

	m_heartbeat_id = ( m_heartbeat_id + 1 ) % 100;
	m_heartbeat_thread.detach();

	this->connect();
}

void dclient_t::on_message( websocketpp::connection_hdl con_hdl, client_t::message_ptr message ) {
	nlohmann::json data = nlohmann::json::parse( message->get_payload() );

	switch ( data["op"].get<disc_gate_op_type>() ) {

		case OP_DISPATCH: {
			std::string& event = data["t"].get_ref<std::string&>();

			if ( event == "MESSAGE_CREATE" || event == "MESSAGE_UPDATE" ) {
				// TODO: Nitro sniper

				// TODO: Command handler
			}

			else if ( event == "READY" ) {
				m_session_id = data["d"]["session_id"].get<std::string>(); // hoping this uses rvo lol

				spdlog::debug( "Successfully started session: {}", m_session_id );

				if ( !m_readied_before ) {
					m_readied_before = true;

					nlohmann::json& userdata = data["d"]["user"];
					spdlog::info( "Successfully authenticated as: {}#{} | ID: {}",
						userdata["username"], userdata["discriminator"], userdata["id"] );
				}
			}

			else if ( event == "RESUMED" ) {
				spdlog::debug( "Successfully resumed session: {}", m_session_id );
			}

			m_last_sequence = data["s"].get<int32_t>();
		}	return;

		case OP_HEARTBEAT:
			this->heartbeat( con_hdl );
			return;

		case OP_RECONNECT: // ill be booted off anyways so im not handling this
			return;

		case OP_INVALID_SESSION:
			if ( data["d"].get<bool>() == false ) {
				m_last_sequence = -1;
				m_session_id.clear();
			}

			this->identify( con_hdl );
			return;

		case OP_HELLO:
			this->identify( con_hdl );

			m_heartbeat_interval = std::chrono::milliseconds( data["d"]["heartbeat_interval"].get<uint32_t>() );
			m_heartbeat_thread = std::thread( &dclient_t::heartbeat_loop, this, con_hdl );
			return;

		case OP_GUILD_SYNC:
		case OP_LOBBY_VOICE_STATES_UPDATE:
		case OP_HEARTBEAT_ACK:
			return; // not handling these bc fuck it

		default:
			return; // shouldnt be received in the first place

	}
}
