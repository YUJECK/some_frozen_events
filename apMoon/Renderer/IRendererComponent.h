//
// Created by destructive_crab on 12/6/23.
//

#ifndef SOME_FROZEN_EVENTS_WORLDSPRITE_H
#define SOME_FROZEN_EVENTS_WORLDSPRITE_H

#include <SFML/Graphics.hpp>
#include "../Component.h"

class IRendererComponent : public Component {

public:
    virtual sf::Drawable* get_drawable() = 0;
    void update_component() override;
    void start_component() override;
    void destroy_component() override;

};


#endif //SOME_FROZEN_EVENTS_WORLDSPRITE_H
