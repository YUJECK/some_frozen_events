//
// Created by destructive_crab on 12/6/23.
//

#include "TestEntity.h"
#include "apMoon/Renderer/SpriteRenderer.h"
#include "MovementComponent.h"
#include "apMoon/Renderer/RendererManager.h"
#include<iostream>
#include<SFML/Graphics.hpp>

void TestEntity::start_entity()
{
    view = new sf::View;

    sf::Texture texture;
    texture.loadFromFile("/home/destructive_crab/CLionProjects/some_frozen_events/Assets/Square.png");

    SpriteRenderer* sp = new SpriteRenderer(texture);

    add_component(new MovementComponent);
    add_component(sp);

    RendererManager::get_instance()->apply_view(view);
}

void TestEntity::destroy_entity()
{

}

void TestEntity::update_entity()
{
    view->setCenter(get_position());
}
