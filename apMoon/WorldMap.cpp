//
// Created by destructive_crab on 12/10/23.
//

#include "WorldMap.h"

WorldMap::WorldMap(sf::Image image) {
    for (int x = 0; x < MAP_WIDTH; ++x) {
        for (int y = 0; y < MAP_HEIGHT; ++y) {
            map[x][y] = process_color(image.getPixel(x, y));
        }
    }
}

int WorldMap::process_color(sf::Color color) {
    if(color == sf::Color(0, 0, 0, 0))
        return 0;
    if(color == sf::Color::White)
        return 1;
    if(color == sf::Color::Red)
        return 2;
    if(color == sf::Color::Green)
        return 3;
    if(color == sf::Color::Blue)
        return 4;

    return 0;
}

int WorldMap::get(int x, int y) {
    return map[x][y];
}
