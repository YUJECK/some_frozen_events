//
// Created by User on 06.01.2024.
//

#include "PlayerShooting.h"
#include "apMoon/Game.h"

#define PIby180 3.14/180

void PlayerShooting::update_component() {
    float dirX = cos(daddy->get_rotation() * PIby180);
    float dirY = sin(daddy->get_rotation() * PIby180);

    if(InputService::get_instance()->is_left_mouse_button_pressed())
    {
        RayData hit = Game::get_instance()->get_map()->raycast(sf::Vector2u(daddy->get_position().x, daddy->get_position().y), sf::Vector2f(dirX, dirY));
        Game::get_instance()->get_map()->replace(hit.position.x, hit.position.y, new MapCell(0, "", false));
    }
}

void PlayerShooting::start_component() {

}

void PlayerShooting::destroy_component() {

}
