//

#include "PlayerTrigger.h"
#include "../../apMoon/Game.h"

//
// Created by destructive_crab on 1/14/24.

PlayerTrigger::PlayerTrigger(int fov) : fov(fov) {}

PlayerTrigger::~PlayerTrigger() {

}

void PlayerTrigger::start_component() {

}

void PlayerTrigger::update_component() {
    isPlayerOnTrigger = check_trigger();
}

void PlayerTrigger::destroy_component() {

}

bool PlayerTrigger::is_triggered() {
    return isPlayerOnTrigger;
}

bool PlayerTrigger::check_trigger() {
    for (int x = -fov; x <= fov; ++x) {
        for (int y = -fov; y <= fov ; ++y) {

            if(daddy->get_position().x + x <= 0 || daddy->get_position().x + x >= MAP_WIDTH
               || daddy->get_position().y + y <= 0 || daddy->get_position().y + y >= MAP_HEIGHT)
                continue;

            if(Game::get_instance()->get_map()->get_cell(daddy->get_position().x + x, daddy->get_position().y + y)->has_entity()
               && Game::get_instance()->get_map()->get_cell(daddy->get_position().x + x, daddy->get_position().y + y)->get_entity()->name == "Player")
            {
                return true;
            }
        }
    }

    return false;
}
