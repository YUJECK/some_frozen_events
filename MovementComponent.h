//
// Created by destructive_crab on 12/6/23.
//

#ifndef SOME_FROZEN_EVENTS_MOVEMENTCOMPONENT_H
#define SOME_FROZEN_EVENTS_MOVEMENTCOMPONENT_H

#include "apMoon/Component.h"

class MovementComponent : public Component
{
public:
    void start_component() override;
    void update_component() override;
    void destroy_component() override;
};


#endif //SOME_FROZEN_EVENTS_MOVEMENTCOMPONENT_H
