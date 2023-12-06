//
// Created by destructive_crab on 12/6/23.
//

#include "Entity.h"
#include<typeinfo>

void Entity::add_component(Component* component) {

    components.push_back(component);
    component->start_component();
}

void Entity::remove_component(Component* component) {

}

void Entity::update_all_components(Component* component) {

}
