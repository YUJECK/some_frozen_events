//
// Created by User on 06.01.2024.
//

#include "Enemy.h"
#include "../../apMoon/Game.h"
#include "../../apMoon/Renderer/SpriteRenderer.h"
#include "PlayerTrigger.h"
#include "EnemyMovement.h"

Enemy::~Enemy() {

}

void Enemy::start_entity() {
    add_component(new PlayerTrigger(fov));
    add_component(new EnemyMovement());
    add_component(new SpriteRenderer(Game::process_path("4.png").data()));
}

void Enemy::update_entity() {
    if(check_trigger())
    {
        SpriteRenderer* component = nullptr;

        if(has_component(component))
            component->change_image(Game::process_path("4red.png").data());
    }
    else
    {
        SpriteRenderer* component = nullptr;

        if(has_component(component))
            component->change_image(Game::process_path("4.png").data());
    }
}

void Enemy::destroy_entity() {

}

bool Enemy::check_trigger() {
    for (int x = -fov; x <= fov; ++x) {
        for (int y = -fov; y <= fov ; ++y) {

            if(get_position().x + x <= 0 || get_position().x + x >= MAP_WIDTH
            || get_position().y + y <= 0 || get_position().y + y >= MAP_HEIGHT)
                continue;

            if(Game::get_instance()->get_map()->get_cell(get_position().x + x, get_position().y + y)->has_entity()
            && Game::get_instance()->get_map()->get_cell(get_position().x + x, get_position().y + y)->get_entity()->name == "Player")
            {
                return true;
            }
        }
    }

    return false;
}