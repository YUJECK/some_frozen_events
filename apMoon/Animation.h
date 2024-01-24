//
// Created by destructive_crab on 21.01.2024.
//

#ifndef SOME_FROZEN_EVENTS_ANIMATION_H
#define SOME_FROZEN_EVENTS_ANIMATION_H

#include "Renderer/SpriteRenderer.h"
#include <chrono>
#include <thread>

class Animation {

private:
    int currentFrame = 0;
    int maxFrame = 0;
    SpriteRenderer * target;
    bool stop;
    sf::Texture spriteSheet;

    void AnimationLoop();

public:
    const int FrameSizeX = 24;

    const int FrameSizeY = 24;

    Animation(const char* sheetPath);
    void Play(SpriteRenderer * spriteRenderer);
    void Stop();
};


#endif //SOME_FROZEN_EVENTS_ANIMATION_H
