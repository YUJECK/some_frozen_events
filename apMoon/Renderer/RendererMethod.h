//
// Created by destructive_crab on 12/7/23.
//
#ifndef RENDERERMETHOD_H
#define RENDERERMETHOD_H


#include<SFML/Graphics.hpp>

class RendererMethod
{
public:
    virtual void Draw(sf::Drawable* drawable, sf::RenderWindow* window) = 0;
};

#endif
