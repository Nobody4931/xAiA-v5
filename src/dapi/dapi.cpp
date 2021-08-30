#define ASIO_STANDALONE

#include "dapi/dapi.hpp"

#include <system_error>
#include <iostream>
#include <sstream>

#include <spdlog/spdlog.h>
#include <asio.hpp>
#include <asio/ssl.hpp>
#include <websocketpp/http/parser.hpp>
#include <websocketpp/http/request.hpp>
#include <websocketpp/http/response.hpp>

#include "config.hpp"

namespace http = websocketpp::http;


static asio::ip::tcp::endpoint dendpoint;

void dapi_setup_endpoint( asio::io_context& io_ctx ) {
	asio::ip::tcp::resolver resolver( io_ctx );
	dendpoint = resolver.resolve( CFG_DAPI_HOSTNAME, CFG_DAPI_PORT )->endpoint();
}

http::parser::response dapi_request( asio::io_context& io_ctx, asio::streambuf& request ) {
	http::parser::response hresponse;

	try {
		asio::ssl::context ssl_ctx( asio::ssl::context_base::tlsv12_client ); // discord uses tls 1.2 apparently
		asio::ssl::stream<asio::ip::tcp::socket> socket( io_ctx, ssl_ctx );

		socket.next_layer().connect( dendpoint );
		socket.handshake( asio::ssl::stream_base::handshake_type::client );

		// Send request
		asio::write( socket, request );

		// Receive response
		std::stringstream response;
		asio::streambuf response_stream;

		asio::error_code err_code; // fuck you stream truncated
		while ( asio::read( socket, response_stream, asio::transfer_at_least( 1 ), err_code ) )
			response << &response_stream;

		// Check error
		if ( err_code != asio::error::eof && err_code != asio::ssl::error::stream_truncated )
			throw asio::system_error( err_code ); // assume error fuck off

		hresponse.consume( response );
	} catch ( const std::exception& error ) {
		spdlog::error( "An error occurred whilst invoking DAPI: {}", error.what() );
	}

	return hresponse;
}
