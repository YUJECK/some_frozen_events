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


        if(InputService::get_instance()->is_key_down(sf::Keyboard::Space))
        {
            std::cout << "-------------" << std::endl;
            for (int i = 0; i < path.size(); ++i) {
                std::cout << path[i].x << " " << path[i].y << std::endl;
            }
            std::cout << "-------------" << std::endl;
        }
    }

}

void EnemyMovement::destroy_component() {

}
