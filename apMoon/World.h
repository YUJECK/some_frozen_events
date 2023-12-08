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
    static World* instance;
    sf::RenderWindow* renderWindow;
    std::vector<Entity*> entities;
    World();
    ~World();
    World& operator=(World);
};