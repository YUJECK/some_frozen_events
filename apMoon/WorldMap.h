//
// Created by destructive_crab on 12/10/23.
//

#ifndef SOME_FROZEN_EVENTS_WORLDMAP_H
#define SOME_FROZEN_EVENTS_WORLDMAP_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "MapCell.h"
#include "Renderer/IRendererComponent.h"
#include "Renderer/RayData.h"

#define MAP_WIDTH 64
#define MAP_HEIGHT 64

#define UP_MAP_WIDTH 64
#define UP_MAP_HEIGHT 64

#define CELL_SIZE 16

class WorldMap {
public:
    WorldMap(sf::Image image);
    ~WorldMap();

    int get(unsigned int x, unsigned int y);
    MapCell * get_cell(unsigned int x, unsigned int y);

    RayData raycast(sf::Vector2u position, sf::Vector2f direction);

    void process_entities(Entity **entitiesPull, int entitiesCount);
    void replace(unsigned int x, unsigned int y, MapCell* to);
    void swap(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);

private:
    MapCell * process_color(sf::Color color);

public:
    const int WIDTH = UP_MAP_WIDTH;
    const int HEIGHT = UP_MAP_HEIGHT;
    const int CELL = CELL_SIZE;

private:
    MapCell* map[MAP_WIDTH*CELL_SIZE][MAP_HEIGHT*CELL_SIZE];
};


#endif //SOME_FROZEN_EVENTS_WORLDMAP_H
