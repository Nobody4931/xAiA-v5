#pragma once
#ifndef DAPI_HEADER_HPP
#define DAPI_HEADER_HPP

#define ASIO_STANDALONE

#include <asio/io_context.hpp>
#include <asio/streambuf.hpp>
#include <websocketpp/http/parser.hpp>
#include <websocketpp/http/request.hpp>
#include <websocketpp/http/response.hpp>


void dapi_setup_endpoint( asio::io_context& io_ctx );

websocketpp::http::parser::response dapi_request( asio::io_context& io_ctx, asio::streambuf& request );

#endif
