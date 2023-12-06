cmake_minimum_required(VERSION 3.26)
project(FreezingNose)

set(CMAKE_CXX_STANDARD 17)

add_executable(FreezingNose apMoon/main.cpp
        apMoon/World.h
        apMoon/World.cpp
        apMoon/Entity.cpp
        apMoon/Entity.h
        apMoon/Component.cpp
        apMoon/Component.h
        TestEntity.cpp
        TestEntity.h)

target_link_libraries(FreezingNose PRIVATE sfml-graphics sfml-system sfml-window)