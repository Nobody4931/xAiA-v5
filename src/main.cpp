#define ASIO_STANDALONE

#include <spdlog/spdlog.h>
#include <asio/io_context.hpp>

#include "config.hpp"
#include "dapi/dapi.hpp"
#include "dgateway/dgateway.hpp"

int main() {
	spdlog::set_level( spdlog::level::trace );
	spdlog::set_pattern( "[%m.%d.%C - %H:%M:%S] [%^%l%$] %v" );

	spdlog::info( "Loading " PROGRAM_NAME " " PROGRAM_VERS "..." );

	// Initialize modules
	asio::io_context io_ctx;

	dapi_setup_endpoint( io_ctx );

	// Setup gateway client
	dclient_t dclient( io_ctx );

	dclient.setup();
	dclient.connect();
	dclient.get_runner_thread().join();

	return 0;
}
