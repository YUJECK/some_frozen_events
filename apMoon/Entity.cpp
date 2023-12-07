//
// Created by destructive_crab on 12/6/23.
//

#include "Entity.h"
#include "../TestComponent.h"
#include<typeinfo>

void Entity::add_component(Component* component)
{
    components[typeid(component).name()] = component;
    component->start_component();
}

void Entity::remove_component(std::type_info componentType)
{
    Component *component = components[componentType.name()];
    components.erase(componentType.name());

    delete component;
}

void Entity::update_all_components()
{
    auto iterator = components.begin();

    for (; iterator != components.end(); iterator++)
    {
        (*iterator).second->update_component();
    }
}
