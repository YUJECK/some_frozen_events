//
// Created by User on 06.01.2024.
//

#include <iostream>
#include "StaticImage.h"

StaticImage::StaticImage(const char* imagePath, sf::Vector2f position, sf::Vector2f scale)
: GUIElement(position, scale)
{
    sprite = new sf::Sprite;
    texture = new sf::Texture;

    texture->loadFromFile(imagePath);
    sprite->setTexture(*texture);

    sprite->setPosition(position.x, position.y);
    sprite->setScale(scale.x, scale.y);
}

bool StaticImage::targetable() {
    return false;
}

void StaticImage::on_pushed() {

}

void StaticImage::draw(sf::RenderWindow *window) {
    window->draw(*sprite);
}

void StaticImage::apply_transform() {
    sprite->setPosition(position.x, position.y);
    sprite->setScale(scale.x, scale.y);

    std::cout << sprite->getPosition().x << " " << sprite->getPosition().y << std::endl;
    std::cout << sprite->getScale().x << " " << sprite->getScale().y << std::endl;
}
