//
// Created by User on 06.01.2024.
//

#include "GUILevel.h"

bool GUILevel::targetable() {
    return false;
}

void GUILevel::draw(sf::RenderWindow *window) {
    for (int i = 0; i < get_children_count(); ++i) {
        get_child(i)->draw(window);
    }
}

GUILevel::GUILevel(const sf::Vector2f &position, const sf::Vector2f &scale) : GUIElement(position, scale) {}
