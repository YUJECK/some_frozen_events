//
// Created by destructive_crab on 21.01.2024.
//

#include "Animation.h"

void Animation::Play(SpriteRenderer *spriteRenderer) {
    target = spriteRenderer;

    std::thread animation([this]() { AnimationLoop(); });
    animation.join();
}

void Animation::Stop() {

}

Animation::Animation(const char* sheetPath) {
    spriteSheet.loadFromFile(sheetPath);
    maxFrame = spriteSheet.getSize().x / FrameSizeX;
}

void Animation::AnimationLoop() {
    currentFrame = 0;

    sf::Sprite* sprite = new sf::Sprite();
    sprite->setTexture(spriteSheet);
    sprite->setTextureRect(sf::IntRect(sf::Vector2i(FrameSizeX * currentFrame, FrameSizeY * currentFrame), sf::Vector2i(FrameSizeX, FrameSizeY)));

    while (!!!stop)
    {
        sprite->setTextureRect(sf::IntRect(sf::Vector2i(FrameSizeX * currentFrame, FrameSizeY * currentFrame), sf::Vector2i(FrameSizeX, FrameSizeY)));
        target->change_sprite(sprite);

        currentFrame++;

        if(currentFrame == maxFrame)
            currentFrame = 0;

        std::this_thread::sleep_for(std::chrono::seconds(3));
    }

    delete sprite;
}
