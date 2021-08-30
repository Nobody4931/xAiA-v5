# Get includes
set(Fmt_INCLUDE_DIR "${PROJECT_DEP_FOLDER}/fmt/include")

# Get version
file(READ "${Fmt_INCLUDE_DIR}/fmt/core.h" _VERSION_H)

if (NOT _VERSION_H MATCHES "#define FMT_VERSION ([0-9]+)")
	message(FATAL_ERROR "Cannot get Fmt version from core.h")
endif ()

math(EXPR _PKG_VER_MAJOR "${CMAKE_MATCH_1} / 10000")
math(EXPR _PKG_VER_MINOR "${CMAKE_MATCH_1} / 100 % 100")
math(EXPR _PKG_VER_PATCH "${CMAKE_MATCH_1} % 100")

string(CONCAT Fmt_VERSION ${_PKG_VER_MAJOR}.${_PKG_VER_MINOR}.${_PKG_VER_PATCH})

# Handle find_package() call
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Fmt
	REQUIRED_VARS Fmt_INCLUDE_DIR
	VERSION_VAR Fmt_VERSION)

mark_as_advanced(Fmt_FOUND Fmt_INCLUDE_DIR Fmt_VERSION)

# Create library
if (Fmt_FOUND AND NOT TARGET Fmt::Fmt)
	add_library(Fmt::Fmt INTERFACE IMPORTED)
	target_include_directories(Fmt::Fmt INTERFACE
		"${Fmt_INCLUDE_DIR}")
endif ()
