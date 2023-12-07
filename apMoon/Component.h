//
// Created by destructive_crab on 12/6/23.
//

#ifndef FREEZINGNOSE_COMPONENT_H
#define FREEZINGNOSE_COMPONENT_H

#include <iostream>

class Component
{
public:
    virtual void start_component() = 0;
    virtual void update_component() = 0;
    virtual void destroy_component() = 0;
};


#endif //FREEZINGNOSE_COMPONENT_H
