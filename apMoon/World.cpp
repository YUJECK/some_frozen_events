#include "iostream"
#include "World.h"
#include "Renderer/RendererManager.h"
#include "Renderer/IRendererComponent.h"
#include "Inputs/InputService.h"

//
// Created by destructive_crab on 12/4/23.
//
World* World::instance = 0;

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
        RendererManager::get_instance()->push(component->get_drawable());
}

void World::delete_entity(Entity *entity) {
    if(entity == nullptr)
        return;

    entity->destroy_entity();
    entities.erase(std::remove(entities.begin(), entities.end(), entity));
    delete entity;
}

void World::start_world()
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

        for (int i = 0; i < entities.size(); ++i) {
            entities[i]->update_entity();
            entities[i]->update_all_components();
        }

        InputService::get_instance()->tick();
        RendererManager::get_instance()->tick();

        renderWindow->display();
    }
}

World::World()
{
    renderWindow = new sf::RenderWindow(sf::VideoMode(600, 600), "SFML not works!");
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
