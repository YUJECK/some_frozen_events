//
// Created by User on 06.01.2024.
//

#ifndef SOME_FROZEN_EVENTS_ENEMY_H
#define SOME_FROZEN_EVENTS_ENEMY_H


#include "../../apMoon/Entity.h"

class Enemy : public Entity {

private:
    int fov = 10;

    bool check_trigger();

public:
    ~Enemy() override;

    void start_entity() override;

    void update_entity() override;

    void destroy_entity() override;
};


#endif //SOME_FROZEN_EVENTS_ENEMY_H
