//
// Created by User on 25.12.2023.
//

#include "MapCell.h"

int MapCell::get_index() {
    return index;
}


MapCell::MapCell(int index, const char* texture_path, bool isDec) {
    this->index = index;
    this->isDecoration = isDec;
    tex_path = texture_path;

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

bool MapCell::is_decoration() {
    return isDecoration;
}

const char *MapCell::get_tex_path() const {
    return tex_path;
}

const Entity *MapCell::get_entity() {
    return entity;
}
void MapCell::set_entity(Entity* entity) {
    this->entity = entity;
}