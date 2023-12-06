#include "iostream"
#include "World.h"

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
}

void World::delete_entity(Entity *entity) {
    if(entity == nullptr)
        return;

    entity->destroy_entity();
    entities.erase(std::remove(entities.begin(), entities.end(), entity));
    delete entity;
}
