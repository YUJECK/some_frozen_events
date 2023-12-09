//
// Created by destructive_crab on 12/6/23.
//

#include <iostream>
#include "MovementComponent.h"
#include "apMoon/Inputs/InputService.h"

void MovementComponent::start_component()
{

}

void MovementComponent::update_component()
{
    if(InputService::get_instance()->is_key_pressed(sf::Keyboard::Key::W))
        daddy->set_position(daddy->get_position().x, daddy->get_position().y-1);

    if(InputService::get_instance()->is_key_pressed(sf::Keyboard::Key::S))
        daddy->set_position(daddy->get_position().x, daddy->get_position().y+1);

    if(InputService::get_instance()->is_key_pressed(sf::Keyboard::Key::A))
        daddy->set_position(daddy->get_position().x-1, daddy->get_position().y);

    if(InputService::get_instance()->is_key_pressed(sf::Keyboard::Key::D))
        daddy->set_position(daddy->get_position().x+1, daddy->get_position().y);
}

void MovementComponent::destroy_component()
{
    std::cout << "Destroy" << std::endl;
}