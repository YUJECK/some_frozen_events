#include "iostream"
#include "World.h"

//
// Created by destructive_crab on 12/4/23.
//
World* World::instance = 0;

World &World::operator=(World) {
    return *this;
}

void World::push_entity(Entity *entity) {
    entities.push_back(entity);
    entity->start_entity();
}

World* World::get_instance() {
    if(instance == nullptr)
        instance = new World;

    return instance;
}
