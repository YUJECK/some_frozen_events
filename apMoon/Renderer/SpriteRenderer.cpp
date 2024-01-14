//
// Created by destructive_crab on 12/8/23.
//

#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer(sf::Texture* tex)
{
    this->texture = tex;
    image = new sf::Image(tex->copyToImage());
    sprite = new sf::Sprite(*tex);
}

SpriteRenderer::SpriteRenderer(const char *path) {
    texture = new sf::Texture;
    texture->loadFromFile(path);

    sprite = new sf::Sprite(*texture);

    image = new sf::Image;
    image->loadFromFile(path);
}

sf::Drawable *SpriteRenderer::get_drawable() {
    return sprite;
}

SpriteRenderer::~SpriteRenderer() {
    delete sprite;
    delete texture;
}

void SpriteRenderer::update_component() { }

void SpriteRenderer::destroy_component() { }

void SpriteRenderer::start_component() { }

sf::Image *SpriteRenderer::get_image() {
    return image;
}

float SpriteRenderer::get_distance_to_player() {
    return std::sqrt(std::abs(this->daddy->get_position().x - Game::get_instance()->get_player_pos().x)
                        +
                        std::abs(this->daddy->get_position().y - Game::get_instance()->get_player_pos().y));
}

void SpriteRenderer::change_image(const char *path) {
    image->loadFromFile(path);
}
