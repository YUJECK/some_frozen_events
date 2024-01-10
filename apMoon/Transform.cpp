//
// Created by destructive_crab on 12/8/23.
//
#include "Transform.h"

Transform::Transform(float x, float y) {
    position = new sf::Vector2f(x, y);
    rotation = new float(0);
}

Transform::Transform() {
    position = new sf::Vector2f(0, 0);
    rotation = new float(0);
}

Transform::~Transform() {
    delete position;
    delete rotation;
}

