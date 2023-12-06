#include <vector>
#include "Entity.h"

class World
{
private:
    static World* instance;
    std::vector<Entity*> entities;
    World() {}
    World& operator=(World);

public:
    static World* get_instance();
    void push_entity(Entity* entity);
};