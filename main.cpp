#include <SFML/Window/Event.hpp>
#include "apMoon/World.h"
#include "TestEntity.h"
#include "TestComponent.h"

int main()
{
    TestEntity *testEntity = new TestEntity;

    testEntity->name = "test";
    //testEntity->set_position(300, 300);

    World::get_instance()->push_entity(testEntity);

    testEntity->add_component(new TestComponent);
    World::get_instance()->start_world();

    delete testEntity;
    return 0;
}