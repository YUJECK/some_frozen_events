//
// Created by destructive_crab on 12/6/23.
//

#include "Entity.h"
#include "../TestComponent.h"
#include<typeinfo>

void Entity::add_component(Component* component) {
    const std::type_info& typeInfo = typeid(component);
    components.insert(typeInfo, component);
    component->start_component();

    TestComponent cp;
    components.insert(typeid(component), cp);
}

void Entity::remove_component(const std::type_info componentType)
{
    Component *component = components[typeid(componentType)];
    components.erase(typeid(componentType));
    delete component;
}

void Entity::update_all_components(Component* component) {

}