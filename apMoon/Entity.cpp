//
// Created by destructive_crab on 12/6/23.
//

#include "Entity.h"
#include "../TestComponent.h"
#include<typeinfo>

void Entity::add_component(Component* component)
{
    components.emplace(&typeid(component), component);
    component->start_component();
}

void Entity::update_all_components()
{
    auto iterator = components.begin();

    for (; iterator != components.end(); iterator++)
    {
        (*iterator).second->update_component();
    }
}