cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(CMAKE_BUILD_TYPE Release)
project(xaia
	VERSION 5.0.0
	DESCRIPTION "my custom discord selfbot"
	LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(PROJECT_LIB_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(PROJECT_DEP_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/dep")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

find_package(Spdlog REQUIRED MODULE)
find_package(JSON REQUIRED MODULE)
find_package(Asio REQUIRED MODULE)
find_package(Websocketpp REQUIRED MODULE)
find_package(OpenSSL REQUIRED MODULE)

set(REQUIRED_LIBS
	Threads::Threads
	Spdlog::Spdlog
	JSON::JSON
	Asio::Asio
	Websocketpp::Websocketpp
	OpenSSL::SSL
	OpenSSL::Crypto)

set(REQUIRED_INCS
	"${Spdlog_INCLUDE_DIR}"
	"${JSON_INCLUDE_DIR}"
	"${Asio_INCLUDE_DIR}"
	"${Websocketpp_INCLUDE_DIR}"
	"${OPENSSL_INCLUDE_DIR}")

add_compile_options("-O2")
add_compile_options("-libstd=libstdc++")

add_subdirectory(src)
