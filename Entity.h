//
// Created by destructive_crab on 12/6/23.
//

#ifndef FREEZINGNOSE_ENTITY_H
#include<iostream>
#define FREEZINGNOSE_ENTITY_H

class Entity {
public:
    std::string name;

private:

public:
    virtual void StartEntity() = 0;
    virtual void UpdateEntity() = 0;
    virtual void DestroyEntity() = 0;
    void AddComponent();
    void RemoveComponent();
    void UpdateAllComponents();
};


#endif //FREEZINGNOSE_ENTITY_H
