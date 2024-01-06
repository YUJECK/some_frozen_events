//
// Created by destructive_crab on 12/6/23.
//

#include "Player.h"
#include "apMoon/Renderer/SpriteRenderer.h"
#include "MovementComponent.h"
#include "PlayerShooting.h"
#include "PlayerHealth.h"
#include<iostream>

void Player::start_entity()
{
    add_component(new MovementComponent);
    add_component(new PlayerShooting);
    add_component(new PlayerHealth);
}

void Player::destroy_entity() { }

void Player::update_entity() { }