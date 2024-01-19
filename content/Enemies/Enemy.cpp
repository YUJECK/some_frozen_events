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
    add_component(new SpriteRenderer(Game::process_path("GreenyCup.png").data()));
}

void Enemy::update_entity() {
}

void Enemy::destroy_entity() {

}