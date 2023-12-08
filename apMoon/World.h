#ifndef SOME_FROZEN_EVENTS_WORLD_H
#define SOME_FROZEN_EVENTS_WORLD_H

#include <vector>
#include <algorithm>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Entity.h"

class World
{
public:
    static World* get_instance();
    sf::RenderWindow* get_window();
    void push_entity(Entity* entity);
    void delete_entity(Entity* entity);
    void start_world();

private:
    sf::RenderWindow* renderWindow;
    std::vector<Entity*> entities;

    static World* instance;
    World();
    ~World();
    World& operator=(World);
};

#endif //SOME_FROZEN_EVENTS_WORLD_H
