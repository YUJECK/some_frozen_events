//
// Created by User on 06.01.2024.
//

#ifndef SOME_FROZEN_EVENTS_PLAYERSHOOTING_H
#define SOME_FROZEN_EVENTS_PLAYERSHOOTING_H


#include "apMoon/Component.h"
#include "apMoon/Inputs/InputService.h"

class PlayerShooting : public Component{
    void update_component() override;

public:
    void start_component() override;

    void destroy_component() override;
};


#endif //SOME_FROZEN_EVENTS_PLAYERSHOOTING_H
