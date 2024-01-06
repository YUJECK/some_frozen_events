//
// Created by destructive_crab on 12/8/23.
//

#ifndef SOME_FROZEN_EVENTS_SPRITERENDERER_H
#define SOME_FROZEN_EVENTS_SPRITERENDERER_H

#include "IRendererComponent.h"
#include "../World.h"
#include <SFML/Graphics.hpp>

class SpriteRenderer : public IRendererComponent
{
public:
    SpriteRenderer(sf::Texture* tex);
    SpriteRenderer(const char* path);
    ~SpriteRenderer();

    sf::Drawable * get_drawable() override;
    sf::Image * get_image() override;

    float get_distance_to_player() override;

    void update_component() override;
    void destroy_component() override;
    void start_component() override;

private:
    sf::Sprite* sprite;
    sf::Image* image;
    sf::Texture* texture;
};


#endif //SOME_FROZEN_EVENTS_SPRITERENDERER_H
