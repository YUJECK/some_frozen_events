//
// Created by destructive_crab on 12/6/23.
//

#ifndef SOME_FROZEN_EVENTS_RENDERERMANAGER_H
#define SOME_FROZEN_EVENTS_RENDERERMANAGER_H


#include "RendererMethod.h"
#include<SFML/Graphics.hpp>

class RendererManager
{
public:
    static RendererManager* get_instance();

    void tick();

    void push(sf::Drawable* drawable);
    void erase(sf::Drawable* drawable);

private:
    static RendererManager* instance;
    RendererMethod* renderer;
    sf::RenderWindow* renderWindow;

    std::vector<sf::Drawable*> drawables;

    RendererManager();
    ~RendererManager();
    RendererManager& operator=(RendererManager);
};


#endif //SOME_FROZEN_EVENTS_RENDERERMANAGER_H
