add_subdirectory(dapi)
add_subdirectory(dgateway)

list(APPEND PROJECT_LIBS dapi)
list(APPEND PROJECT_LIBS dgateway)

add_executable(${PROJECT_NAME}
	main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
	${PROJECT_LIBS})
target_include_directories(${PROJECT_NAME} PRIVATE
	"${PROJECT_LIB_FOLDER}")

target_link_libraries(${PROJECT_NAME} PRIVATE
	${REQUIRED_LIBS})
target_include_directories(${PROJECT_NAME} PRIVATE
	${REQUIRED_INCS})
