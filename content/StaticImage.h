//
// Created by User on 06.01.2024.
//

#ifndef SOME_FROZEN_EVENTS_STATICIMAGE_H
#define SOME_FROZEN_EVENTS_STATICIMAGE_H


#include "../apMoon/GUI/GUIElement.h"

class StaticImage : public GUIElement {
private:
    sf::Sprite * sprite;
    sf::Texture * texture;
protected:
    void apply_transform() override;

public:
    StaticImage(const char* imagePath, sf::Vector2f position, sf::Vector2f scale);

    bool targetable() override;

    void draw(sf::RenderWindow *window) override;
    void on_pushed() override;
};


#endif //SOME_FROZEN_EVENTS_STATICIMAGE_H
