//
// Created by destructive_crab on 12/6/23.
//

#ifndef SOME_FROZEN_EVENTS_RENDERERMANAGER_H
#define SOME_FROZEN_EVENTS_RENDERERMANAGER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "RendererMethod.h"
#include "../Inputs/InputService.h"
#include "Pseudo3DRenderer.h"

class RendererManager
{
public:
    static RendererManager* get_instance();

    void tick();

    void apply_view(sf::View* view);
    void push(IRendererComponent* drawable);
    void erase(IRendererComponent* drawable);

private:
    RendererManager();
    ~RendererManager();
    static bool compare_decorations(IRendererComponent *left, IRendererComponent *right);

    static RendererManager* instance;

    RendererMethod* renderer;
    sf::RenderWindow* renderWindow;

    sf::View* view;
    std::vector<IRendererComponent*> drawables;

    RendererManager& operator=(RendererManager);
};


#endif //SOME_FROZEN_EVENTS_RENDERERMANAGER_H
