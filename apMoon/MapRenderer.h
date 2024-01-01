//
// Created by User on 29.12.2023.
//

#ifndef SOME_FROZEN_EVENTS_MAPRENDERER_H
#define SOME_FROZEN_EVENTS_MAPRENDERER_H


#include "Renderer/RendererMethod.h"

class MapRenderer : public RendererMethod
{
    void draw(IRendererComponent **drawable, int drawablesCount, sf::RenderWindow *window) override;
};


#endif //SOME_FROZEN_EVENTS_MAPRENDERER_H
