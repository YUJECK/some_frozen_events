cmake_minimum_required(VERSION 3.26)
project(some_frozen_events)

set(CMAKE_CXX_STANDARD 20)

add_executable(some_frozen_events main.cpp
        apMoon/World.h
        apMoon/World.cpp
        apMoon/Entity.cpp
        apMoon/Entity.h
        apMoon/Component.cpp
        apMoon/Component.h
        TestEntity.cpp
        TestEntity.h
        apMoon/Renderer/RendererManager.cpp
        apMoon/Renderer/RendererManager.h
        apMoon/Renderer/WorldSprite.cpp
        apMoon/Renderer/WorldSprite.h
        TestComponent.cpp
        TestComponent.h
)

target_link_libraries(some_frozen_events PRIVATE sfml-graphics sfml-system sfml-window)
