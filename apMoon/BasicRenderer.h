//
// Created by User on 06.01.2024.
//

#ifndef SOME_FROZEN_EVENTS_BASICRENDERER_H
#define SOME_FROZEN_EVENTS_BASICRENDERER_H


#include "Renderer/RendererMethod.h"

class BasicRenderer : public RendererMethod {
public:
    void draw(IRendererComponent **drawable, int drawablesCount, sf::RenderWindow *window) override;
};


#endif //SOME_FROZEN_EVENTS_BASICRENDERER_H
