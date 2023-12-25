#include <cstring>
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
    renderWindow = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML not works!");
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

    player = dynamic_cast<Player *>(entity);
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
        entities[i]->destroy_entity();
        delete entities[i];
    }
    delete instance;
}

WorldMap *World::get_map() {
    return map;
}

void World::load_map(sf::Image image) {
    map = new WorldMap(image);
    const char* path = "";

    const char* ASSETS_FOLDER = "D:/VS PROJECTS/C++/sfe/some_frozen_events-curr-/Assets";

    for (int x = 0; x < map->WIDTH; ++x) {
        for (int y = 0; y < map->HEIGHT; ++y) {
            if(map->get(x, y) > 0)
            {
                if(map->get(x, y) == 1)
                    path = "D:\\VS PROJECTS\\C++\\sfe\\some_frozen_events-curr-\\Assets\\1.png";
                if (map->get(x, y) == 2)
                    path = "D:\\VS PROJECTS\\C++\\sfe\\some_frozen_events-curr-\\Assets\\2.png";
                if(map->get(x, y) == 3)
                    path = "D:\\VS PROJECTS\\C++\\sfe\\some_frozen_events-curr-\\Assets\\3.png";
                if(map->get(x, y) == 4)
                    path = "D:\\VS PROJECTS\\C++\\sfe\\some_frozen_events-curr-\\Assets\\4.png";

                Wall *wall = new Wall(path);
                wall->set_position(x*map->CELL, y*map->CELL);
                push_entity(wall);
            }
        }
    }
}

Player *World::get_player() {
    return player;
}

sf::Vector2<float> World::get_player_pos() {
    return player->get_position();
}
