//
// Created by destructive_crab on 12/10/23.
//

#ifndef SOME_FROZEN_EVENTS_WORLDMAP_H
#define SOME_FROZEN_EVENTS_WORLDMAP_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "MapCell.h"

#define MAP_WIDTH 36
#define MAP_HEIGHT 36
#define CELL_SIZE 16

class WorldMap {
public:
    WorldMap(sf::Image image);
    ~WorldMap();

    int get(int x, int y);
    MapCell * get_cell(int x, int y);

private:
    MapCell * process_color(sf::Color color);

public:
    const int WIDTH = MAP_WIDTH;
    const int HEIGHT = MAP_HEIGHT;
    const int CELL = CELL_SIZE;

private:
    MapCell* map[MAP_WIDTH][MAP_HEIGHT];
};


#endif //SOME_FROZEN_EVENTS_WORLDMAP_H
