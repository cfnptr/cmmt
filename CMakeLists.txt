cmake_minimum_required(VERSION 3.10)

if(${CMAKE_SOURCE_DIR} MATCHES ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "Prevented in-tree build")
endif()

project(cmmt 
	VERSION 0.1.0
	DESCRIPTION "Common mathematics library"
	HOMEPAGE_URL "https://github.com/cfnptr/cmmt"
	LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

configure_file(
	cmake/defines.h.in
	cmmt/defines.h)

add_library(cmmt INTERFACE)

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
	target_link_libraries(cmmt INTERFACE m)
endif()

target_include_directories(cmmt INTERFACE
	${PROJECT_BINARY_DIR}
	${PROJECT_SOURCE_DIR}/include)
