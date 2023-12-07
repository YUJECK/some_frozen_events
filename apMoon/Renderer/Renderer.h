//
// Created by destructive_crab on 12/7/23.
//

#ifndef SOME_FROZEN_EVENTS_RENDERER_H
#define SOME_FROZEN_EVENTS_RENDERER_H

#endif //SOME_FROZEN_EVENTS_RENDERER_H

#include<SFML/Graphics.hpp>

class Renderer
{
public:
    virtual void Draw(sf::Drawable* drawable) = 0;
};