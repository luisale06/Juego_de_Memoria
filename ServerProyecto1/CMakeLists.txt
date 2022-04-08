cmake_minimum_required(VERSION 3.21)
project(ServerProyecto1)

set(CMAKE_CXX_STANDARD 23)

add_executable(ServerProyecto1 main.cpp Server.cpp Server.h Card.cpp Card.h Board.cpp Board.h Type.cpp Type.h)
target_link_libraries(ServerProyecto1 ws2_32)
target_link_libraries(ServerProyecto1 libws2_32.a)

set(SFML_STATIC_LIBRARIES TREUE)
set(SFML_DIR E:/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(E:/SFML-2.5.1/include)
target_link_libraries(ServerProyecto1 sfml-system sfml-window sfml-graphics sfml-audio)
