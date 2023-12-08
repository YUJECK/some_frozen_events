//
// Created by destructive_crab on 12/6/23.
//

#include "Component.h"

void Component::set_daddy(Entity* entity) {
    daddy = entity;
}

Component::~Component() {
    delete daddy;
}
