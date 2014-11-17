cmake_minimum_required(VERSION 2.8)

project(tcp_ip_parsing_project)
set(headers Parsing_functions.hpp)
set(sources New_server.cpp Parsing_functions.cpp)

add_executable(server ${sources} ${headers})
add_executable(client client.cpp)


