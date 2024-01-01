//
// Created by destructive_crab on 12/10/23.
//

#include "WorldMap.h"

WorldMap::WorldMap(sf::Image image) {

    for (int x = 0; x < UP_MAP_WIDTH; ++x) {
        for (int y = 0; y < UP_MAP_HEIGHT; ++y) {
            map[x][y] = process_color(image.getPixel(x, y));
        }
    }
}

WorldMap::~WorldMap() {

    for (int x = 0; x < UP_MAP_WIDTH; ++x) {
        for (int y = 0; y < UP_MAP_HEIGHT; ++y) {
            delete map[x][y];
        }
    }
}

MapCell * WorldMap::process_color(sf::Color color) {
    MapCell* cell;

    char* path0 = "";
    char* path1 = "D:\\VS PROJECTS\\C++\\sfe\\some_frozen_events-curr-\\Assets\\1.png";
    char* path2 = "D:\\VS PROJECTS\\C++\\sfe\\some_frozen_events-curr-\\Assets\\2.png";
    char* path3 = "D:\\VS PROJECTS\\C++\\sfe\\some_frozen_events-curr-\\Assets\\3.png";
    char* path4 = "D:\\VS PROJECTS\\C++\\sfe\\some_frozen_events-curr-\\Assets\\4.png";

    if(color == sf::Color(0, 0, 0, 0))
        cell = new MapCell(0, path0);
    if(color == sf::Color::White)
        cell = new MapCell(1, path1);
    if(color == sf::Color::Red)
        cell = new MapCell(2, path2);
    if(color == sf::Color::Green)
        return new MapCell(3, path3);
    if(color == sf::Color::Blue)
        cell = new MapCell(4, path4);

    return cell;
}

int WorldMap::get(int x, int y) {
    return map[x][y]->get_index();
}

MapCell * WorldMap::get_cell(int x, int y) {
    return map[x][y];
}
