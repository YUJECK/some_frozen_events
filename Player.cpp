//
// Created by destructive_crab on 12/6/23.
//

#include "Player.h"
#include "apMoon/Renderer/SpriteRenderer.h"
#include "MovementComponent.h"
#include<iostream>

void Player::start_entity()
{
    SpriteRenderer* sp = new SpriteRenderer("D:\\VS PROJECTS\\C++\\sfe\\some_frozen_events-curr-\\Assets\\Square.png");

    add_component(new MovementComponent);
    add_component(sp);
}

void Player::destroy_entity()
{

}

void Player::update_entity()
{
}
