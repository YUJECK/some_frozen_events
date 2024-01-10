//
// Created by User on 06.01.2024.
//

#ifndef SOME_FROZEN_EVENTS_RAYDATA_H
#define SOME_FROZEN_EVENTS_RAYDATA_H


#include "../MapCell.h"

class RayData {
public:
    RayData(MapCell *hit, sf::Vector2u position);

    MapCell * hit;
    sf::Vector2u position;
};


#endif //SOME_FROZEN_EVENTS_RAYDATA_H
