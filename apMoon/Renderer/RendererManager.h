//
// Created by destructive_crab on 12/6/23.
//

#ifndef FREEZINGNOSE_RENDERERMANAGER_H
#define FREEZINGNOSE_RENDERERMANAGER_H


#include "Renderer.h"
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
    Renderer* renderer;

    std::vector<sf::Drawable*> drawables;

    RendererManager(){ }
    RendererManager& operator=(RendererManager);
};


#endif //FREEZINGNOSE_RENDERERMANAGER_H
