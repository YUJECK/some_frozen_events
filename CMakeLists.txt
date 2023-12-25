cmake_minimum_required(VERSION 3.26)
project(some_frozen_events)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(libs/SFML)

add_executable(some_frozen_events main.cpp
        apMoon/World.h
        apMoon/World.cpp
        apMoon/Entity.h
        apMoon/Entity.cpp
        apMoon/Component.cpp
        apMoon/Component.h
        Player.cpp
        Player.h
        apMoon/Renderer/RendererManager.cpp
        apMoon/Renderer/RendererManager.h
        apMoon/Renderer/IRendererComponent.h
        MovementComponent.cpp
        MovementComponent.h
        apMoon/Renderer/RendererMethod.h
        apMoon/Renderer/SpriteRenderer.cpp
        apMoon/Renderer/SpriteRenderer.h
        apMoon/Renderer/BaseRenderer.cpp
        apMoon/Renderer/BaseRenderer.h
        apMoon/Transform.h
        apMoon/Transform.cpp
        apMoon/Inputs/InputService.cpp
        apMoon/Inputs/InputService.h
        apMoon/WorldMap.cpp
        apMoon/WorldMap.h
        Wall.cpp
        Wall.h
        apMoon/Renderer/Stripe.cpp
        apMoon/Renderer/Stripe.h
)

target_link_libraries(some_frozen_events PRIVATE sfml-graphics sfml-system sfml-window)