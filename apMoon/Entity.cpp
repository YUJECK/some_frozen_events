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
    for (int i = 0; i < components.size(); ++i)
    {
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

void Entity::rotate(float rotation) {
    float primaryAngle = *transform->rotation + rotation;

    if (primaryAngle > 360 || primaryAngle < 0)
    {
        primaryAngle = (int)rotation % 360;

        if(primaryAngle < 0)
            primaryAngle += 360;
    }

    *transform->rotation = primaryAngle;
}

Entity::~Entity() {
    for (int i = 0; i < components.size(); ++i) {
        if(components[i])
        {
            components[i]->destroy_component();
            delete components[i];
        }
    }

    delete transform;
}

Entity::Entity() {
    transform = new Transform;
}
