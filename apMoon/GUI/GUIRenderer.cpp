//
// Created by User on 06.01.2024.
//

#include "GUIRenderer.h"

GUIRenderer* GUIRenderer::instance = 0;

void GUIRenderer::tick() {
    for (int i = 0; i < levels.size(); ++i) {
        levels[i]->on_update();
    }
}

void GUIRenderer::resize(sf::Vector2u prevSize, sf::Vector2u newSize) {
    for (int i = 0; i < levels.size(); ++i) {
        levels[i]->on_resize(prevSize, newSize);
    }
}

void GUIRenderer::draw(sf::RenderWindow *window) {
    for (int i = 0; i < levels.size(); ++i) {
        levels[i]->draw(window);
    }
}

void GUIRenderer::push_level(GUILevel *level) {
    levels.push_back(level);
    level->on_pushed();
}

GUIRenderer::~GUIRenderer() {
    for (int i = 0; i < levels.size(); ++i) {
        delete levels[i];
    }
}

GUIRenderer *GUIRenderer::get_instance() {
    if(instance == nullptr)
        instance = new GUIRenderer;

    return instance;
}
