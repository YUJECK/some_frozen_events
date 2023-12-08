//
// Created by destructive_crab on 12/6/23.
//

#include "Entity.h"

void Entity::add_component(Component* component)
{
    components.push_back(component);
    component->set_daddy(this);
    component->start_component();
}

void Entity::update_all_components()
{
    for (int i = 0; i < components.size(); ++i) {
        components[i]->update_component();
    }
}

sf::Vector2<float> Entity::get_position() {
    return *transform->position;
}

void Entity::set_position(sf::Vector2<float> position) {
    transform->position = &position;
}
void Entity::set_position(float x, float y) {
    transform->position->x = x;
    transform->position->y = y;
}

float Entity::get_rotation() {
    return *transform->rotation;
}

void Entity::set_rotation(float rotation) {
    transform->rotation = &rotation;
}

Entity::~Entity() {
    for (int i = 0; i < components.size(); ++i) {
        delete components[i];
    }

    delete transform;
}
