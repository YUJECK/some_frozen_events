//
// Created by destructive_crab on 12/8/23.
//

#include "SpriteRenderer.h"

sf::Drawable *SpriteRenderer::get_drawable() {
    return sprite;
}

SpriteRenderer::SpriteRenderer(sf::Texture image)
{
    sprite = new sf::Sprite(image);
}

SpriteRenderer::~SpriteRenderer() {
    delete sprite;
}

void SpriteRenderer::update_component() {
    std::cout << (daddy->get_position().x) << " " << (daddy->get_position().y)<< std::endl;
    sprite->setPosition(daddy->get_position());
}

void SpriteRenderer::destroy_component() {

}

void SpriteRenderer::start_component()
{
    std::cout << "start" << std::endl;
}
