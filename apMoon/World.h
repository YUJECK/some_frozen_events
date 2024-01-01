#ifndef SOME_FROZEN_EVENTS_WORLD_H
#define SOME_FROZEN_EVENTS_WORLD_H

#include <vector>
#include <algorithm>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Entity.h"
#include "WorldMap.h"
#include "../Player.h"

class World
{
public:
    static World* get_instance();
    sf::RenderWindow* get_window();
    WorldMap* get_map();
    Player* get_player();
    sf::Vector2<float> get_player_pos();

    void push_entity(Entity* entity);
    void delete_entity(Entity* entity);
    void load_map(sf::Image image);
    void start_game_loop();

private:
    World();
    ~World();

    static World* instance;

    sf::RenderWindow* renderWindow;
    Player* player;
    WorldMap *map;
    std::vector<Entity*> entities;

    World& operator=(World);
};

#endif //SOME_FROZEN_EVENTS_WORLD_H
