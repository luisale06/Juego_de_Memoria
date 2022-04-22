cmake_minimum_required(VERSION 3.22)
project(Server)

set(CMAKE_CXX_STANDARD 14)

add_executable(Server main.cpp Card.cpp Card.h Type.cpp Type.h)
target_link_libraries(Server ws2_32)
target_link_libraries(Server libws2_32.a)