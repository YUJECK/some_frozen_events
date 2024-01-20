#include "iostream"
#include "Game.h"
#include "Renderer/RendererManager.h"
#include "Renderer/IRendererComponent.h"
#include "Inputs/InputService.h"
#include "../Wall.h"
#include "Scene.h"
#include "GUI/GUIRenderer.h"
#include <cstring>

//
// Created by destructive_crab on 12/4/23.
//
Game* Game::instance = 0;

Game::Game()
{
    renderWindow = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "SFML not works!", sf::Style::Fullscreen);
    windowSize = renderWindow->getSize();
}

Game &Game::operator=(Game) {
    return *this;
}

Game* Game::get_instance() {
    if(instance == nullptr)
        instance = new Game;

    return instance;
}

void Game::push_entity(Entity *entity) {
    if(entity == nullptr)
        return;

    entities.push_back(entity);
    entity->start_entity();

    IRendererComponent* component = nullptr;

    if(entity->has_component(component))
        RendererManager::get_instance()->push(component);

    if(!player)
        player = dynamic_cast<Player *>(entity);
}

void Game::delete_entity(Entity *entity) {
    if(entity == nullptr)
        return;

    entity->destroy_entity();
    entities.erase(std::remove(entities.begin(), entities.end(), entity));
    delete entity;
}

void Game::start_game_loop()
{
    while (renderWindow->isOpen())
    {
        renderWindow->clear();

        InputService::get_instance()->tick();

        map->process_entities(entities.data(), entities.size());

        for (int i = 0; i < entities.size(); ++i) {
            entities[i]->update_entity();
            entities[i]->update_all_components();
        }

        RendererManager::get_instance()->tick();

        GUIRenderer::get_instance()->tick();
        GUIRenderer::get_instance()->draw(renderWindow);
        renderWindow->display();
    }
}

sf::RenderWindow* Game::get_window() {
    return renderWindow;
}

Game::~Game() {
    for (int i = 0; i < entities.size(); ++i) {
        entities[i]->destroy_entity();
        delete entities[i];
    }
    delete instance;
}

WorldMap *Game::get_map() {
    return map;
}

void Game::load_map(sf::Image image) {
    map = new WorldMap(image);
}
void Game::load_scene(Scene * scene)
{
    if(currentScene)
        delete currentScene;

    for (int i = 0; i < entities.size(); ++i) {
        delete entities[i];
    }

    currentScene = scene;
    scene->upload();
}

std::string Game::process_path(std::string resource)
{
    return "/home/destructive_crab/dev/ussless_beard/Assets/" + resource;
}

Player *Game::get_player() {
    return player;
}

sf::Vector2<float> Game::get_player_pos() {
    return player->get_position();
}
