//
// Created by destructive_crab on 12/8/23.
//
#include "Transform.h"

Transform::Transform(float x, float y) {
    position = new sf::Vector2<float>(x, y);
    rotation = new float(0);
}

Transform::Transform() {
    position = new sf::Vector2<float>(0, 0);
    rotation = new float(0);
}

Transform::~Transform() {
    delete position;
    delete rotation;
}

