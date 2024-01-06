//
// Created by User on 06.01.2024.
//

#ifndef SOME_FROZEN_EVENTS_GUILEVEL_H
#define SOME_FROZEN_EVENTS_GUILEVEL_H


#include "GUIElement.h"

class GUILevel : public GUIElement {
public:
    GUILevel(const sf::Vector2f &position, const sf::Vector2f &scale);

    bool targetable() override;

    void draw(sf::RenderWindow *window) override;
};


#endif //SOME_FROZEN_EVENTS_GUILEVEL_H
