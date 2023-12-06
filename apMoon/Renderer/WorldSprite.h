//
// Created by destructive_crab on 12/6/23.
//

#ifndef FREEZINGNOSE_WORLDSPRITE_H
#define FREEZINGNOSE_WORLDSPRITE_H

#include <SFML/Graphics.hpp>

class WorldSprite {

public:
    virtual sf::Drawable get_drawable() = 0;

};


#endif //FREEZINGNOSE_WORLDSPRITE_H
