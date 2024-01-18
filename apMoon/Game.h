#ifndef SOME_FROZEN_EVENTS_GAME_H
#define SOME_FROZEN_EVENTS_GAME_H

#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Entity.h"
#include "WorldMap.h"
#include "../Player.h"
#include "Scene.h"

class Game
{
public:
    static Game* get_instance();
    sf::RenderWindow* get_window();
    WorldMap* get_map();
    Player* get_player();
    sf::Vector2<float> get_player_pos();

    void push_entity(Entity* entity);
    void delete_entity(Entity* entity);
    void load_map(sf::Image image);
    void load_scene(Scene *scene);
    static std::string process_path(std::string resource);

    void start_game_loop();
private:
    Game();

    ~Game();

    static Game* instance;
    sf::RenderWindow* renderWindow;
    Scene * currentScene = 0;
    Player* player = 0;
    WorldMap *map;
    sf::Vector2u windowSize;

    std::vector<Entity*> entities;

    Game& operator=(Game);
};

#endif //SOME_FROZEN_EVENTS_GAME_H
