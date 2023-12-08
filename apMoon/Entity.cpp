//
// Created by destructive_crab on 12/6/23.
//

#include "Entity.h"
#include "../TestComponent.h"
#include<typeinfo>

void Entity::add_component(Component* component)
{
    components.push_back(component);
    component->start_component();
}

void Entity::update_all_components()
{
    for (int i = 0; i < components.size(); ++i) {
        components[i]->update_component();
    }
}