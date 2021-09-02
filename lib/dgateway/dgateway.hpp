#pragma once
#ifndef DGATEWAY_HEADER_HPP
#define DGATEWAY_HEADER_HPP

#define ASIO_STANDALONE

#include <cstdint>
#include <chrono>
#include <memory>
#include <functional>
#include <thread>
#include <map>

#include <nlohmann/json.hpp>
#include <websocketpp/client.hpp>
#include <websocketpp/config/asio_client.hpp>
#include <websocketpp/connection.hpp>

#include "config.hpp"
#include "dgateway/dtypes.hpp"
#include "dgateway/dobjects.hpp"


#define DGATE_ENDPOINT "wss://gateway.discord.gg/?v=" CFG_DAPI_VERS_GATE "&encoding=json"


class dclient_t {
public:
	using client_t = websocketpp::client<websocketpp::config::asio_tls_client>;

public:
	dclient_t( asio::io_context& io_ctx )
		: m_io_ctx( io_ctx )
		, m_ssl_ctx( std::make_shared<asio::ssl::context>( asio::ssl::context_base::method::tlsv12_client ) )
		, m_heartbeat_id( 0 )
		, m_readied_before( false )
		, m_last_sequence( -1 )
	{
		m_client.clear_access_channels( websocketpp::log::alevel::all );
		m_client.clear_error_channels( websocketpp::log::elevel::all );

		m_client.init_asio();
		m_client.start_perpetual();

		m_client.set_tls_init_handler( std::bind( &dclient_t::get_ssl_ctx, this ) );

		m_runner_thread = std::thread( &client_t::run, &m_client );
	}

	~dclient_t() = default;

	dclient_t( const dclient_t& other ) = delete;
	dclient_t( dclient_t&& other ) = delete;

	dclient_t& operator=( const dclient_t& other ) = delete;
	dclient_t& operator=( dclient_t&& other ) = delete;

public:
	void setup();
	void connect();

private:
	void on_close( websocketpp::connection_hdl con_hdl );
	void on_message( websocketpp::connection_hdl con_hdl, client_t::message_ptr message );

	void heartbeat( websocketpp::connection_hdl con_hdl );
	void heartbeat_loop( websocketpp::connection_hdl con_hdl );
	void identify( websocketpp::connection_hdl con_hdl );

public:
	inline client_t& get_client() { return m_client; }

	inline std::thread& get_runner_thread() { return m_runner_thread; }
	inline std::thread& get_heartbeat_thread() { return m_heartbeat_thread; }

	inline std::shared_ptr<asio::ssl::context> get_ssl_ctx() { return m_ssl_ctx; }

private:
	client_t m_client;

	std::thread m_runner_thread;
	std::thread m_heartbeat_thread;

	asio::io_context& m_io_ctx;
	std::shared_ptr<asio::ssl::context> m_ssl_ctx;

	std::string m_base_headers;
	nlohmann::json m_super_properties;

	uint8_t m_heartbeat_id;
	std::chrono::milliseconds m_heartbeat_interval;

	bool m_readied_before;
	std::string m_session_id;
	int32_t m_last_sequence;

	std::map<dsnowflake_t, dguild_t*> m_guilds;
	std::map<dsnowflake_t, duser_t*> m_users;
};

#endif
