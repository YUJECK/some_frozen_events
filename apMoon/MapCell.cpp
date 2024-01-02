//
// Created by User on 25.12.2023.
//

#include <iostream>
#include "MapCell.h"

int MapCell::get_index() {
    return index;
}


MapCell::MapCell(int index, char* texture_path) {
    this->index = index;

    if(index > 0)
    {
        image.loadFromFile(texture_path);
    }
}

MapCell::~MapCell() {
}

sf::Color MapCell::get_pixel(int x, int y) {
    return image.getPixel(x, y);
}
