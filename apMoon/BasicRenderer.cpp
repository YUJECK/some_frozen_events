//
// Created by User on 06.01.2024.
//

#include "BasicRenderer.h"

void BasicRenderer::draw(IRendererComponent **drawable, int drawablesCount, sf::RenderWindow *window) {
    for (int i = 0; i < drawablesCount; ++i) {
        window->draw(*drawable[i]->get_drawable());
    }
}
