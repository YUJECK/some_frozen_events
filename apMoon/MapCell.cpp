//
// Created by User on 25.12.2023.
//

#include "MapCell.h"

int MapCell::get_index() {
    return index;
}

sf::Texture* MapCell::get_texture() {
    return texture;
}

MapCell::MapCell(int index, char* texture_path) {
    this->index = index;

    if(index > 0)
    {
        texture = new sf::Texture();
        texture->loadFromFile(texture_path);
    }
}

MapCell::~MapCell() {
    delete texture;
}
