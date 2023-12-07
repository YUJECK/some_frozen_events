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
    std::map<const std::type_info*, Component*> components;

public:
    virtual void start_entity() = 0;
    virtual void update_entity() = 0;
    virtual void destroy_entity() = 0;

    template<class TComponent>
    TComponent* get_component()
    {
        return (TComponent*)components[&typeid(TComponent)];
    }

    template<class TComponent>
    bool has_component(TComponent& out)
    {
        if(components.contains(&typeid(TComponent)))
        {
            out = (TComponent)components[&typeid(TComponent)];
            return true;
        }

        delete out;
        return false;
    }

    void add_component(Component* component);

    template<class TComponent>
    void remove_component()
    {
        Component *component = components[&typeid(TComponent)];
        components.erase(&typeid(TComponent));

        delete component;
    }

    void update_all_components();
};


#endif //FREEZINGNOSE_ENTITY_H
