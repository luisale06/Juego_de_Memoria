cmake_minimum_required(VERSION 3.21)
project(Proyecto_1)

set(CMAKE_CXX_STANDARD 23)

add_executable(Proyecto_1 main.cpp Client.cpp Client.h)
target_link_libraries(Proyecto_1 ws2_32)
target_link_libraries(Proyecto_1 libws2_32.a)

set(SFML_STATIC_LIBRARIES TREUE)
set(SFML_DIR E:/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(E:/SFML-2.5.1/include)
target_link_libraries(Proyecto_1 sfml-system sfml-window sfml-graphics sfml-audio)
