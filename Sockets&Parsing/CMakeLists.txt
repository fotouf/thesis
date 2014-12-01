cmake_minimum_required(VERSION 2.8)

project(tcp_ip_parsing_project)
set(headers Rapid_Parsing_functions.hpp)
set(sources New_server.cpp Rapid_Parsing_functions.cpp)
SET(CMAKE_BUILD_TYPE RELEASE)
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -O3")

add_executable(server ${sources} ${headers})
add_executable(client client.cpp)


