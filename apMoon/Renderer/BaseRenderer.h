//
// Created by destructive_crab on 12/8/23.
//

#ifndef SOME_FROZEN_EVENTS_BASERENDERER_H
#define SOME_FROZEN_EVENTS_BASERENDERER_H


#include "RendererMethod.h"

class BaseRenderer : public RendererMethod
{
public:
    void Draw(sf::Drawable* drawable, sf::RenderWindow* window) override;
};


#endif //SOME_FROZEN_EVENTS_BASERENDERER_H
