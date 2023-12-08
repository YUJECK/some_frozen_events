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
    std::vector<Component *> components;

public:
    virtual void start_entity() = 0;

    virtual void update_entity() = 0;

    virtual void destroy_entity() = 0;

    void add_component(Component* component);

    template<class TComponent>
    bool has_component(TComponent &out)
    {
        int index = get_component_index<TComponent>();

        if(index < components.size())
        {
            out = (TComponent)components[index];
            return true;
        }

        return false;
    }

    template<class TComponent>
    bool has_component()
    {
        return get_component_index<TComponent>() == components.size();
    }

    template<class TComponent>
    int get_component_index()
    {
        for(int i = 0; i < components.size(); i++)
        {
            if(dynamic_cast<TComponent>(components[i]))
                return i;
        }

        return components.size();
    }

    template<class TComponent>
    Component* get_component()
    {
        return components[get_component_index<TComponent>()];
    }

    template<class TComponent>
    void remove_component()
    {
        Component* component = nullptr;

        if(has_component<TComponent>(component))
            delete component;
    }

    void update_all_components();
};


#endif //FREEZINGNOSE_ENTITY_H
