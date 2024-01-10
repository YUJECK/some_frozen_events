//
// Created by destructive_crab on 12/6/23.
//

#ifndef SOME_FROZEN_EVENTS_COMPONENT_H
#define SOME_FROZEN_EVENTS_COMPONENT_H

#include <iostream>
#include "Entity.h"

class Entity;

class Component
{
protected:
    Entity* daddy;
public:
    Component();
    virtual ~Component();

    void set_daddy(Entity* entity);
    Entity* get_daddy() const;

    virtual void start_component() = 0;
    virtual void update_component() = 0;
    virtual void destroy_component() = 0;
};


#endif //SOME_FROZEN_EVENTS_COMPONENT_H
