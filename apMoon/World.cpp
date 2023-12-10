#include "iostream"
#include "World.h"
#include "Renderer/RendererManager.h"
#include "Renderer/IRendererComponent.h"
#include "Inputs/InputService.h"
#include "../Wall.h"

//
// Created by destructive_crab on 12/4/23.
//
World* World::instance = 0;

World::World()
{
    renderWindow = new sf::RenderWindow(sf::VideoMode(600, 600), "SFML not works!");
}

World &World::operator=(World) {
    return *this;
}

World* World::get_instance() {
    if(instance == nullptr)
        instance = new World;

    return instance;
}

void World::push_entity(Entity *entity) {
    if(entity == nullptr)
        return;

    entities.push_back(entity);
    entity->start_entity();

    IRendererComponent* component = nullptr;

    if(entity->has_component(component))
        RendererManager::get_instance()->push(component);
}

void World::delete_entity(Entity *entity) {
    if(entity == nullptr)
        return;

    entity->destroy_entity();
    entities.erase(std::remove(entities.begin(), entities.end(), entity));
    delete entity;
}

void World::start_game_loop()
{
    while (renderWindow->isOpen())
    {
        renderWindow->clear();


        sf::Event event;
        while (renderWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                renderWindow->close();
            }
        }

        InputService::get_instance()->tick();

        for (int i = 0; i < entities.size(); ++i) {
            entities[i]->update_entity();
            entities[i]->update_all_components();
        }

        RendererManager::get_instance()->tick();
        renderWindow->display();
    }
}

sf::RenderWindow* World::get_window() {
    return renderWindow;
}

World::~World() {
    for (int i = 0; i < entities.size(); ++i) {
        delete entities[i];
    }
    delete instance;
}

WorldMap *World::get_map() {
    return map;
}

void World::load_map(sf::Image image) {
    map = new WorldMap(image);

    for (int x = 0; x < map->WIDTH; ++x) {
        for (int y = 0; y < map->HEIGHT; ++y) {
            if(map->get(x, y) == 1)
            {
                Wall *wall = new Wall("/home/destructive_crab/CLionProjects/some_frozen_events/Assets/Wall.png");
                wall->set_position(x*map->CELL, y*map->CELL);
                push_entity(wall);
            }
        }
    }
}
