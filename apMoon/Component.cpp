//
// Created by destructive_crab on 12/6/23.
//

#include "Component.h"

void Component::set_daddy(Entity* entity) {
    std::cout << entity->name << std::endl;
    daddy = entity;
}

Component::Component() {
    daddy = nullptr;
}

Component::~Component() {
    if(daddy)
        delete daddy;
}
