//
// Created by User on 06.01.2024.
//

#ifndef SOME_FROZEN_EVENTS_GUIRENDERER_H
#define SOME_FROZEN_EVENTS_GUIRENDERER_H

#include "GUILevel.h"

class GUIRenderer {
private:
    std::vector<GUILevel*> levels;
    static GUIRenderer * instance;

public:
    virtual ~GUIRenderer();

    static GUIRenderer * get_instance();

    void push_level(GUILevel * level);
    void tick();
    void draw(sf::RenderWindow * window);
    void resize(sf::Vector2u prevSize, sf::Vector2u newSize);
};


#endif //SOME_FROZEN_EVENTS_GUIRENDERER_H
