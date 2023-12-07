//
// Created by destructive_crab on 12/6/23.
//

#include <iostream>
#include "RendererManager.h"

RendererManager* RendererManager::instance = 0;

RendererManager* RendererManager::get_instance() {
    if(instance == nullptr)
        instance = new RendererManager;

    return instance;
}

void RendererManager::push(sf::Drawable *drawable) {
    drawables.push_back(drawable);

    std::cout << "OHUET" << std::endl;
}

void RendererManager::erase(sf::Drawable *drawable) {
    drawables.erase(std::remove(drawables.begin(), drawables.end(), drawable));
    delete drawable;
}

void RendererManager::tick() {
    for (int i = 0; i < drawables.size(); ++i)
    {
        renderer->Draw(drawables[i]);
    }
}

RendererManager &RendererManager::operator=(RendererManager) {
    return *this;
}
