//
// Created by destructive_crab on 12/8/23.
//

#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer(sf::Texture image)
{
    sprite = new sf::Sprite(image);
}

SpriteRenderer::SpriteRenderer(char *path) {
    sf::Texture texture;

    texture.loadFromFile(path);
    sprite = new sf::Sprite();
    sprite->setTexture(texture);
}

sf::Drawable *SpriteRenderer::get_drawable() {
    return sprite;
}

SpriteRenderer::~SpriteRenderer() {
    delete sprite;
}

void SpriteRenderer::update_component() {
    sprite->setPosition(daddy->get_position());
}

void SpriteRenderer::destroy_component() {

}

void SpriteRenderer::start_component()
{
}
