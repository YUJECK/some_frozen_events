//
// Created by User on 25.12.2023.
//

#include "MapCell.h"
#include "Renderer/IRendererComponent.h"

int MapCell::get_index() {
    return index;
}

MapCell::MapCell(int index, std::string texture_path, bool isDec) {
    this->index = index;
    this->isDecoration = isDec;
    tex_path = texture_path;

    if(index > 0)
    {
        wallSprite.loadFromFile(texture_path);
    }
}

MapCell::~MapCell() {
}

sf::Color MapCell::get_pixel(int x, int y) {
    return wallSprite.getPixel(x, y);
}

bool MapCell::is_decoration() {
    return isDecoration;
}

std::string MapCell::get_tex_path() const {
    return tex_path;
}

const Entity *MapCell::get_entity() {
    return entity;
}

void MapCell::set_entity(Entity* newEntity) {
    this->entity = newEntity;

    if(entity != nullptr)
    {
        IRendererComponent* component = nullptr;

        if(entity->has_component(component))
            isDecoration = true;
    }
}

bool MapCell::has_entity() {
    if(this->entity == nullptr)
        return false;

    return entity;
}
