cmake_minimum_required(VERSION 3.10)
project(sockets)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(sockets src/server.cpp)

target_link_libraries(sockets ws2_32)
