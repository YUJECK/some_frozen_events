//
// Created by User on 29.12.2023.
//

#include "MapRenderer.h"

void MapRenderer::draw(IRendererComponent **drawable, int drawablesCount, sf::RenderWindow *window)
{
    for (int i = 0; i < drawablesCount; ++i) {
        window->draw(*drawable[i]->get_drawable());
    }
}