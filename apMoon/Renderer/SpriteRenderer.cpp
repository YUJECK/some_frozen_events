//
// Created by destructive_crab on 12/8/23.
//

#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer(sf::Texture* texture)
{
    this->texture = texture;
    sprite = new sf::Sprite(*texture);
}

SpriteRenderer::SpriteRenderer(const char *path) {
    texture = new sf::Texture;

    texture->loadFromFile(path);
    sprite = new sf::Sprite();
    sprite->setTexture(*texture);
}

sf::Drawable *SpriteRenderer::get_drawable() {
    return sprite;
}

SpriteRenderer::~SpriteRenderer() {
    delete sprite;
    delete texture;
}

void SpriteRenderer::update_component() {
    sprite->setPosition(daddy->get_position());
}

void SpriteRenderer::destroy_component() {

}

void SpriteRenderer::start_component()
{
}
