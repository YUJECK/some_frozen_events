//
// Created by User on 06.01.2024.
//

#include "IntroLevel.h"
#include "../apMoon/Game.h"
#include "PlayerHUD.h"
#include "../apMoon/GUI/GUIRenderer.h"

void IntroLevel::upload() {
    PlayerHUD * hud = new PlayerHUD(sf::Vector2f(0,0), sf::Vector2f(0,0));

    GUIRenderer::get_instance()->push_level(hud);

    Player *testEntity = new Player;
    testEntity->set_position(3, 3);

    sf::Image image;
    testEntity->name = "test";
    image.loadFromFile("/home/destructive_crab/CLionProjects/some_frozen_events/Assets/FirstLevel.png");

    Game::get_instance()->load_map(image);
    Game::get_instance()->push_entity(testEntity);
}
