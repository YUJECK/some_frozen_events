#include <SFML/Graphics.hpp>
#include "apMoon/World.h"
#include "Player.h"

int main()
{
    srand(time(NULL));

    Player *testEntity = new Player;
    testEntity->set_position(3, 3);

    sf::Image image;
    testEntity->name = "test";
    image.loadFromFile("D:\\VS PROJECTS\\C++\\sfe\\some_frozen_events-curr-\\Assets\\FirstLevel.png");

    World::get_instance()->load_map(image);
    World::get_instance()->push_entity(testEntity);
    World::get_instance()->start_game_loop();

    delete testEntity;
    return 0;
}