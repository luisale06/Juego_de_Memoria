cmake_minimum_required(VERSION 3.22)
project(Client)

set(CMAKE_CXX_STANDARD 14)

add_executable(Client main.cpp)
target_link_libraries(Client ws2_32)
target_link_libraries(Client libws2_32.a)

set(SFML_STATIC_LIBRARIES TREUE)
set(SFML_DIR E:/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(E:/SFML-2.5.1/include)
target_link_libraries(Client sfml-system sfml-window sfml-graphics sfml-audio)
