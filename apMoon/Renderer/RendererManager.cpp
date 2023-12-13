//
// Created by destructive_crab on 12/6/23.
//

#include <iostream>
#include "RendererManager.h"
#include "BaseRenderer.h"
#include "../World.h"

RendererManager* RendererManager::instance = 0;

RendererManager* RendererManager::get_instance() {
    if(instance == nullptr)
        instance = new RendererManager;

    return instance;
}

void RendererManager::push(IRendererComponent *drawable) {
    drawables.push_back(drawable);
}

void RendererManager::erase(IRendererComponent *drawable) {
    drawables.erase(std::remove(drawables.begin(), drawables.end(), drawable));
    delete drawable;
}

void RendererManager::tick() {

    if(view)
    {
        renderWindow->setView(*view);
    }

    renderer->draw(drawables.data(), drawables.size(), renderWindow);
}

RendererManager &RendererManager::operator=(RendererManager) {
    return *this;
}

RendererManager::RendererManager() {
    renderer = new BaseRenderer;
    renderWindow = World::get_instance()->get_window();
}

RendererManager::~RendererManager() {
    delete renderer;
    delete instance;
}

void RendererManager::apply_view(sf::View *view) {
    this->view = view;
}
