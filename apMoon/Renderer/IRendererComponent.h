//
// Created by destructive_crab on 12/6/23.
//

#ifndef SOME_FROZEN_EVENTS_IRENDERERCOMPONENT_H
#define SOME_FROZEN_EVENTS_IRENDERERCOMPONENT_H

#include <SFML/Graphics.hpp>
#include "../Component.h"
#include "cmath"

class IRendererComponent : public Component {

public:
    virtual sf::Drawable* get_drawable() = 0;
    virtual sf::Image* get_image() = 0;
    virtual float get_distance_to_player() = 0;

    virtual void update_component() override = 0;
    virtual void start_component() override = 0;
    virtual void destroy_component() override = 0;
};

#endif //SOME_FROZEN_EVENTS_IRENDERERCOMPONENT_H