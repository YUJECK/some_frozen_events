//
// Created by User on 06.01.2024.
//

#include "PlayerHUD.h"
#include "StaticImage.h"

PlayerHUD::PlayerHUD(const sf::Vector2f &position, const sf::Vector2f &scale) : GUILevel(position, scale) {}

void PlayerHUD::on_pushed() {
    add_child(new StaticImage("D:\\VS PROJECTS\\C++\\sfe\\some_frozen_events-curr-\\Assets\\0.png", sf::Vector2f(100, 100), sf::Vector2f(1, 1)));
}

void PlayerHUD::on_update() {

}

bool PlayerHUD::targetable() {
    return true;
}

void PlayerHUD::apply_transform() {

}
