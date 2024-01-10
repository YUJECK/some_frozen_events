//
// Created by destructive_crab on 12/6/23.
//

#ifndef SOME_FROZEN_EVENTS_MOVEMENTCOMPONENT_H
#define SOME_FROZEN_EVENTS_MOVEMENTCOMPONENT_H

#include "apMoon/Component.h"

class MovementComponent : public Component
{
private:
    double PIby180;
    float rotateSpeed = 2;

    float get_x_move();
    float get_y_move();

    bool check_collisions(sf::Vector2f pos);
public:
    void start_component() override;
    void update_component() override;
    void destroy_component() override;

};


#endif //SOME_FROZEN_EVENTS_MOVEMENTCOMPONENT_H
