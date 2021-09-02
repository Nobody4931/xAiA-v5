#pragma once


#define ASIO_STANDALONE

#include <asio/io_context.hpp>
#include <asio/streambuf.hpp>
#include <websocketpp/http/parser.hpp>
#include <websocketpp/http/request.hpp>
#include <websocketpp/http/response.hpp>

#include "config.hpp"


#define DAPI_ENDPOINT "/api/v" CFG_DAPI_VERS_API


void dapi_setup_endpoint( asio::io_context& io_ctx );

websocketpp::http::parser::response dapi_request( asio::io_context& io_ctx, asio::streambuf& request );
