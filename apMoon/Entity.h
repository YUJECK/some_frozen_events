//
// Created by destructive_crab on 12/6/23.
//

#ifndef FREEZINGNOSE_ENTITY_H
#include<iostream>
#include<map>
#include<vector>
#include<typeinfo>
#include "Component.h"

#define FREEZINGNOSE_ENTITY_H

class Entity {
public:
    std::string name;

private:
    std::map<const std::type_info, Component*> components;

public:
    virtual void start_entity() = 0;
    virtual void update_entity() = 0;
    virtual void destroy_entity() = 0;

    void add_component(Component* component);

    void remove_component(const std::type_info componentType);

    void update_all_components(Component* component);
};


#endif //FREEZINGNOSE_ENTITY_H
