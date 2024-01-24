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

    spriteRenderer = new SpriteRenderer(Game::process_path("GreenyCup.png").data());
    add_component(spriteRenderer);

    walkAnimation = new Animation(Game::process_path("GreenyCup-Sheet.png").data());
    walkAnimation->Play(spriteRenderer);
}

void Enemy::update_entity() {
}

void Enemy::destroy_entity() {

}