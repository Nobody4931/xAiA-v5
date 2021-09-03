add_library(dcache STATIC)

target_include_directories(dcache PRIVATE
	"${PROJECT_LIB_FOLDER}")

target_link_libraries(dcache PUBLIC
	${REQUIRED_LIBS})
target_include_directories(dcache PUBLIC
	${REQUIRED_INCS})
