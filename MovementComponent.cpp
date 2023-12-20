//
// Created by destructive_crab on 12/6/23.
//

#include <iostream>
#include <math.h>
#include "MovementComponent.h"
#include "apMoon/Inputs/InputService.h"
#include "apMoon/World.h"

#define PI 3.14159265359

void MovementComponent::start_component()
{

}

void MovementComponent::update_component() {
    if (InputService::get_instance()->is_key_pressed(sf::Keyboard::Key::W)) {
        daddy->set_position(daddy->get_position().x + cos(daddy->get_rotation() * (PI / 180)),
                            daddy->get_position().y + sin(daddy->get_rotation() * (PI / 180)));

        if (World::get_instance()->get_map()->get(daddy->get_position().x / CELL_SIZE, daddy->get_position().y / CELL_SIZE ) > 0)
        {
            daddy->set_position(daddy->get_position().x - cos(daddy->get_rotation() * (PI / 180)),
                                daddy->get_position().y - sin(daddy->get_rotation() * (PI / 180)));
        }
    }

    if (InputService::get_instance()->is_key_pressed(sf::Keyboard::Key::S)) {
        daddy->set_position(daddy->get_position().x - cos(daddy->get_rotation() * (PI / 180)),
                            daddy->get_position().y - sin(daddy->get_rotation() * (PI / 180)));

        if (World::get_instance()->get_map()->get(daddy->get_position().x / CELL_SIZE, daddy->get_position().y / CELL_SIZE) > 0)
        {
            daddy->set_position(daddy->get_position().x + cos(daddy->get_rotation() * (PI / 180)),
                                daddy->get_position().y + sin(daddy->get_rotation() * (PI / 180)));
        }
    }


    if (InputService::get_instance()->is_key_pressed(sf::Keyboard::Key::D))
        daddy->rotate(1);

    if (InputService::get_instance()->is_key_pressed(sf::Keyboard::Key::A))
        daddy->rotate(-1);
}

void MovementComponent::destroy_component()
{
    std::cout << "Destroy" << std::endl;
}