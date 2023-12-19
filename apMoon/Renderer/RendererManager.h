//
// Created by destructive_crab on 12/6/23.
//

#ifndef SOME_FROZEN_EVENTS_RENDERERMANAGER_H
#define SOME_FROZEN_EVENTS_RENDERERMANAGER_H

#include "RendererMethod.h"
#include<SFML/Graphics.hpp>

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 720

class RendererManager
{
public:
    static RendererManager* get_instance();

    void tick();

    void apply_view(sf::View* view);
    void push(IRendererComponent* drawable);
    void erase(IRendererComponent* drawable);

private:
    static RendererManager* instance;
    RendererMethod* renderer;
    sf::RenderWindow* renderWindow;
    sf::View* view;

    std::vector<IRendererComponent*> drawables;
    IRendererComponent* drawables_test[];

    RendererManager();
    ~RendererManager();
    RendererManager& operator=(RendererManager);
};


#endif //SOME_FROZEN_EVENTS_RENDERERMANAGER_H
