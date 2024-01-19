//
// Created by destructive_crab on 1/14/24.
//

#include "EnemyMovement.h"
#include "../../apMoon/Game.h"
#include "../../apMoon/Inputs/InputService.h"

EnemyMovement::~EnemyMovement() {

}

void EnemyMovement::start_component() {
    daddy->has_component(playerTrigger);
}

void EnemyMovement::update_component() {

    if(playerTrigger->check_trigger())
    {
        auto path = pathfinder.get_path(
                sf::Vector2u(daddy->get_position().x,daddy->get_position().y),
                sf::Vector2u(Game::get_instance()->get_player_pos().x, Game::get_instance()->get_player_pos().y));

        get_daddy()->move_position(sf::Vector2f(path[path.size()-1].x, path[path.size()-1].y) , 0.1f);
    }
}

void EnemyMovement::destroy_component() {

}
