# Copyright 2021-2022 Nikita Fediuchin. All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.10)

if(${CMAKE_SOURCE_DIR} MATCHES ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "Prevented in-tree build")
endif()

if (TARGET cmmt)
	return()
endif ()

project(cmmt 
	VERSION 0.1.2
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
