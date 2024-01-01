//
// Created by User on 25.12.2023.
//

#ifndef SOME_FROZEN_EVENTS_MAPCELL_H
#define SOME_FROZEN_EVENTS_MAPCELL_H


#include "SFML/Graphics/Texture.hpp"

class MapCell {
public:
    MapCell(int index, char* texture_path);
    ~MapCell();

public:
    int get_index();
    sf::Texture* get_texture();
private:
    int index;
    sf::Texture * texture;

};


#endif //SOME_FROZEN_EVENTS_MAPCELL_H
