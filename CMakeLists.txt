cmake_minimum_required(VERSION 3.26)
project(linedrawer_simulator)

set(CMAKE_CXX_STANDARD 14)

#find_package(SDL2 REQUIRED)

add_executable(linedrawer_simulator
        main.cpp)
target_link_libraries(linedrawer_simulator -lSDL_bgi)
target_link_libraries(linedrawer_simulator -lSDL2)