#include <SFML/Window/Event.hpp>
#include "apMoon/World.h"
#include "Player.h"
#include "MovementComponent.h"

int main()
{
    Player *testEntity = new Player;

    testEntity->name = "test";
    testEntity->set_position(300, 300);

    sf::Image image;
    image.loadFromFile("/home/destructive_crab/CLionProjects/some_frozen_events/Assets/FirstLevel.png");

    World::get_instance()->load_map(image);
    World::get_instance()->push_entity(testEntity);
    World::get_instance()->start_game_loop();

    delete testEntity;
    return 0;
}