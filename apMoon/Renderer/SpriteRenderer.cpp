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
