#include <vector>
#include "Entity.h"

class World
{
private:
    std::vector<Entity*> test;

public:
    World();
    void push_entity(Entity* entity);
};