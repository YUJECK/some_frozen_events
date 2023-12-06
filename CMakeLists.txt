cmake_minimum_required(VERSION 3.26)
project(FreezingNose)

set(CMAKE_CXX_STANDARD 17)

add_executable(FreezingNose main.cpp
        World.h
        World.cpp
        Entity.cpp
        Entity.h)

target_link_libraries(FreezingNose PRIVATE sfml-graphics sfml-system sfml-window)