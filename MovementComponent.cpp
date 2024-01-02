//
// Created by destructive_crab on 12/6/23.
//w
#include <math.h>
#include "MovementComponent.h"
#include "apMoon/Inputs/InputService.h"
#include "apMoon/World.h"

#define PI 3.14159265359

void MovementComponent::start_component()
{
    PIby180 = PI / 180;
}

void MovementComponent::update_component() {

    if (InputService::get_instance()->is_key_pressed(sf::Keyboard::Key::W)) {
        daddy->set_position(daddy->get_position().x + get_x_move(),
                            daddy->get_position().y + get_y_move());

        if (check_collisions(daddy->get_position()))
        {
            daddy->set_position(daddy->get_position().x - get_x_move(),
                                daddy->get_position().y - get_y_move());
        }
    }

    if (InputService::get_instance()->is_key_pressed(sf::Keyboard::Key::S)) {
        daddy->set_position(daddy->get_position().x - get_x_move(),
                            daddy->get_position().y - get_y_move());

        if (check_collisions(daddy->get_position()))
        {
            daddy->set_position(daddy->get_position().x + get_x_move(),
                                daddy->get_position().y + get_y_move());
        }
    }


    if (InputService::get_instance()->is_key_pressed(sf::Keyboard::Key::D))
        daddy->rotate(1.5);

    if (InputService::get_instance()->is_key_pressed(sf::Keyboard::Key::A))
        daddy->rotate(-1.5);
}

void MovementComponent::destroy_component() { }

float MovementComponent::get_x_move() {
    return cos(daddy->get_rotation() * PIby180) / 5;
}

float MovementComponent::get_y_move() {
    return sin(daddy->get_rotation() * PIby180) / 5;
}

bool MovementComponent::check_collisions(sf::Vector2f pos) {
    return World::get_instance()->get_map()->get(pos.x, pos.y) > 0;
}