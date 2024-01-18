//
// Created by User on 25.12.2023.
//

#ifndef SOME_FROZEN_EVENTS_MAPCELL_H
#define SOME_FROZEN_EVENTS_MAPCELL_H


#include "SFML/Graphics/Texture.hpp"
#include "Entity.h"

class MapCell {
public:
    MapCell(int index, std::string texture_path, bool dec);
    ~MapCell();

    bool is_decoration();

    bool has_entity();

    int get_index();
    const Entity *get_entity();
    sf::Color get_pixel(int x, int y);

    void set_entity(Entity *newEntity);

    std::string get_tex_path() const;
private:
    int index;
    bool isDecoration;
    std::string tex_path;
    sf::Image wallSprite;

    Entity * entity = 0;
};


#endif //SOME_FROZEN_EVENTS_MAPCELL_H
