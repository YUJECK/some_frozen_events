//
// Created by destructive_crab on 12/8/23.
//

#ifndef SOME_FROZEN_EVENTS_TRANSFORM_H
#define SOME_FROZEN_EVENTS_TRANSFORM_H

#include<SFML/Graphics.hpp>

class Transform {
public:
    Transform();
    Transform(float x, float y);
    ~Transform();

    sf::Vector2<float>* position;
    float* rotation;
};


#endif //SOME_FROZEN_EVENTS_TRANSFORM_H
