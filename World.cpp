#include "World.h"
#include "iostream"

//
// Created by destructive_crab on 12/4/23.
//

void World::push_entity(Entity *entity) {
    test.push_back(entity);
    std::cout << test[0]->name;
}

World::World() {
}
