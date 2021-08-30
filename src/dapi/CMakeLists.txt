add_library(dapi STATIC
	dapi.cpp)

target_include_directories(dapi PRIVATE
	"${PROJECT_LIB_FOLDER}")

target_link_libraries(dapi PUBLIC
	${REQUIRED_LIBS})
target_include_directories(dapi PUBLIC
	${REQUIRED_INCS})
