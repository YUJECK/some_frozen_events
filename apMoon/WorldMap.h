//
// Created by destructive_crab on 12/10/23.
//

#ifndef SOME_FROZEN_EVENTS_WORLDMAP_H
#define SOME_FROZEN_EVENTS_WORLDMAP_H

#include <iostream>
#include <SFML/Graphics.hpp>

#define MAP_WIDTH 100
#define MAP_HEIGHT 80
#define CELL_SIZE 16

class WorldMap {
public:
    WorldMap(sf::Image image);

    int get(int x, int y);

private:
    int process_color(sf::Color color);

public:
    const int WIDTH = 100;
    const int HEIGHT = 80;
    const int CELL = 16;

private:
    int map[MAP_WIDTH][MAP_HEIGHT];
};


#endif //SOME_FROZEN_EVENTS_WORLDMAP_H
