#include <SFML/Window/Event.hpp>
#include "apMoon/World.h"
#include "TestEntity.h"
#include "MovementComponent.h"

int main()
{
    TestEntity *testEntity = new TestEntity;

    testEntity->name = "test";
    testEntity->set_position(300, 300);

    World::get_instance()->push_entity(testEntity);

    World::get_instance()->start_game_loop();

    delete testEntity;
    return 0;
}