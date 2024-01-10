
//
// Created by User on 06.01.2024.

#include "GUIElement.h"

GUIElement::GUIElement(const sf::Vector2f &position, const sf::Vector2f &scale)
:
        position(position),
        scale(scale),
        basePosition(position),
        baseScale(scale) {}

GUIElement::~GUIElement() {

}

GUIElement *GUIElement::get_parent() {
    return parent;
}

GUIElement *GUIElement::get_child(int index) {
    return children[index];
}

const int GUIElement::get_children_count() {
    return children.size();
}

void GUIElement::set_parent(GUIElement * newParent) {
    parent = newParent;
}

int GUIElement::add_child(GUIElement *child) {
    child->set_parent(this);
    children.push_back(child);

    return children.size() - 1;
}

void GUIElement::remove_child(int index) {
    children.erase(children.begin() + index);
}

void GUIElement::on_update() {

}

void GUIElement::on_pointed() {

}

void GUIElement::on_pointing() {

}

void GUIElement::on_pointing_released() {

}

void GUIElement::on_resize(sf::Vector2u prevWindowSize, sf::Vector2u windowSize) {
    if(prevWindowSize.x == 0)
        return;

    position.x = basePosition.x * ((float)prevWindowSize.x / (float)windowSize.x);
    position.y = basePosition.y * ((float)prevWindowSize.y / (float)windowSize.y);

    scale.x = baseScale.x * ((float)prevWindowSize.x / (float)windowSize.x);
    scale.y = baseScale.y * ((float)prevWindowSize.y / (float)windowSize.y);

    apply_transform();

    for (int i = 0; i < get_children_count(); ++i) {
        get_child(i)->on_resize(prevWindowSize, windowSize);
    }
}

void GUIElement::on_pushed() {

}