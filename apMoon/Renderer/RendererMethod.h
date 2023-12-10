//
// Created by destructive_crab on 12/7/23.
//
#ifndef SOME_FROZEN_EVENTS_RENDERERMETHOD_H
#define SOME_FROZEN_EVENTS_RENDERERMETHOD_H


#include<SFML/Graphics.hpp>
#include "IRendererComponent.h"

class RendererMethod
{
public:
    virtual void Draw(IRendererComponent *drawable, sf::RenderWindow* window) = 0;
};

#endif //SOME_FROZEN_EVENTS_RENDERERMETHOD_H
