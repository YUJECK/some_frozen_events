//
// Created by User on 06.01.2024.
//

#ifndef SOME_FROZEN_EVENTS_HEALTH_H
#define SOME_FROZEN_EVENTS_HEALTH_H


#include "apMoon/Component.h"

class Health : public Component{
    int health = 60;
private:
    virtual void die() = 0;
public:
    virtual int current();
    virtual bool hit(int health);
    virtual void heal(int health);

    void start_component() override;

    void update_component() override;

    void destroy_component() override;
};


#endif //SOME_FROZEN_EVENTS_HEALTH_H
