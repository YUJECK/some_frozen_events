//
// Created by User on 06.01.2024.
//

#ifndef SOME_FROZEN_EVENTS_GUIELEMENT_H
#define SOME_FROZEN_EVENTS_GUIELEMENT_H

#include <vector>
#include "SFML/Graphics.hpp"

/*
|TopLeft        TopCenter      TopRight   |
|                                         |
|CenterLeft     Center         CenterRight|
|                                         |
|BottomLeft     BottomCenter   BottomRight|
*/

enum Anchor
{
    TopLeft,
    TopCenter,
    TopRight,
    CenterLeft,
    Center,
    CenterRight,
    BottomLeft,
    BottomCenter,
    BottomRight
};

class GUIElement {
private:
    GUIElement* parent;
    std::vector<GUIElement*> children;

public:
    sf::Vector2f position;
    sf::Vector2f basePosition;
    sf::Vector2f scale;
    sf::Vector2f baseScale;

    virtual bool targetable() = 0;
    virtual void draw(sf::RenderWindow * window) = 0;

protected:
    virtual void apply_transform() = 0;

public:
    GUIElement(const sf::Vector2f &position, const sf::Vector2f &scale);

    virtual ~GUIElement();

    GUIElement* get_parent();
    void set_parent(GUIElement * newParent);
    GUIElement* get_child(int index);
    int add_child(GUIElement * child);
    void remove_child(int index);
    const int get_children_count();

    virtual void on_pushed();
    virtual void on_update();
    virtual void on_resize(sf::Vector2u prevWindowSize, sf::Vector2u windowSize);
    virtual void on_pointed();
    virtual void on_pointing();
    virtual void on_pointing_released();
};


#endif //SOME_FROZEN_EVENTS_GUIELEMENT_H
