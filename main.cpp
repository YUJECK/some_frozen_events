#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "apMoon/World.h"
#include "TestEntity.h"
#include "TestComponent.h"

int main() {
    sf::RenderWindow renderWindow(sf::VideoMode(600, 600), "SFML not works!");

    TestEntity* testEntity = new TestEntity;

    testEntity->name = "Test";

    World::get_instance()->push_entity(testEntity);

    testEntity->add_component(new TestComponent);

    testEntity->get_component(typeid(TestComponent).name())->start_component();

    while (renderWindow.isOpen())
    {
        sf::Event event;
        while (renderWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                renderWindow.close();
        }

        renderWindow.clear();
        renderWindow.display();
    }

    return 0;
}
