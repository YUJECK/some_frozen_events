#include "World.h"
#include "iostream"

//
// Created by destructive_crab on 12/4/23.
//

void World::push_entity(Entity *entity) {
    entities.push_back(entity);
    entity->start_entity();
    std::cout << entity->name;
}

World::World() {
}
