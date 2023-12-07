#include "iostream"
#include "World.h"
#include "Renderer/RendererManager.h"
#include "Renderer/SpriteRenderer.h"

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

    SpriteRenderer* component;

    if(entity->has_component(component))
        RendererManager::get_instance()->push(component->get_drawable());

    delete component;
}

void World::delete_entity(Entity *entity) {
    if(entity == nullptr)
        return;

    entity->destroy_entity();
    entities.erase(std::remove(entities.begin(), entities.end(), entity));
    delete entity;
}
