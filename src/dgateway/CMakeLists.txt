add_library(dgateway STATIC
	dgateway.cpp)

target_include_directories(dgateway PRIVATE
	"${PROJECT_LIB_FOLDER}")

target_link_libraries(dgateway PUBLIC
	${REQUIRED_LIBS})
target_include_directories(dgateway PUBLIC
	${REQUIRED_INCS})
