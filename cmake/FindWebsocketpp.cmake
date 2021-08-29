# Get includes
set(Websocketpp_INCLUDE_DIR "${PROJECT_DEP_FOLDER}/websocketpp")

# Get version
file(READ "${Websocketpp_INCLUDE_DIR}/websocketpp/version.hpp" _VERSION_H)

if (NOT _VERSION_H MATCHES "static int const major_version = ([0-9]+);")
	message(FATAL_ERROR "Cannot get Websocketpp major version from version.hpp")
endif ()

math(EXPR _PKG_VER_MAJOR "${CMAKE_MATCH_1}")

if (NOT _VERSION_H MATCHES "static int const minor_version = ([0-9]+);")
	message(FATAL_ERROR "Cannot get Websocketpp minor version from version.hpp")
endif ()

math(EXPR _PKG_VER_MINOR "${CMAKE_MATCH_1}")

if (NOT _VERSION_H MATCHES "static int const patch_version = ([0-9]+);")
	message(FATAL_ERROR "Cannot get Websocketpp patch version from version.hpp")
endif ()

math(EXPR _PKG_VER_PATCH "${CMAKE_MATCH_1}")

string(CONCAT Websocketpp_VERSION ${_PKG_VER_MAJOR}.${_PKG_VER_MINOR}.${_PKG_VER_PATCH})

# Handle find_package() call
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Websocketpp
	REQUIRED_VARS Websocketpp_INCLUDE_DIR
	VERSION_VAR Websocketpp_VERSION)

mark_as_advanced(Websocketpp_FOUND Websocketpp_INCLUDE_DIR Websocketpp_VERSION)

# Create library
if (Websocketpp_FOUND AND NOT TARGET Websocketpp::Websocketpp)
	add_library(Websocketpp::Websocketpp INTERFACE IMPORTED)
	target_include_directories(Websocketpp::Websocketpp INTERFACE
		"${Websocketpp_INCLUDE_DIR}")
endif ()
