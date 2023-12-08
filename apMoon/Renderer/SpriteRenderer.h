//
// Created by destructive_crab on 12/8/23.
//

#ifndef SOME_FROZEN_EVENTS_SPRITERENDERER_H
#define SOME_FROZEN_EVENTS_SPRITERENDERER_H

#include "IRendererComponent.h"
#include <SFML/Graphics.hpp>

class SpriteRenderer : public IRendererComponent{
public:
    SpriteRenderer(sf::Texture image);
    ~SpriteRenderer();

    sf::Drawable * get_drawable() override;

private:
    sf::Sprite* sprite;
};


#endif //SOME_FROZEN_EVENTS_SPRITERENDERER_H
