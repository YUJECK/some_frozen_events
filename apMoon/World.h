#include <vector>
#include <algorithm>
#include "Entity.h"

class World
{
public:
    static World* get_instance();
    void push_entity(Entity* entity);
    void delete_entity(Entity* entity);

private:
    static World* instance;
    std::vector<Entity*> entities;
    World() {}
    World& operator=(World);
};