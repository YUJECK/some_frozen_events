//
// Created by destructive_crab on 12/8/23.
//

#ifndef SOME_FROZEN_EVENTS_BASERENDERER_H
#define SOME_FROZEN_EVENTS_BASERENDERER_H

#include "RendererMethod.h"
#include "../World.h"

class BaseRenderer : public RendererMethod
{
private:
    void drawLine(int x, int y1, int y2, sf::RenderWindow * window);
    sf::RenderWindow* window1;
public:
    void draw(IRendererComponent *drawables[],  int drawablesCount, sf::RenderWindow* window) override;
};


#endif //SOME_FROZEN_EVENTS_BASERENDERER_H
