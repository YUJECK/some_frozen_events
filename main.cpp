#include "World.h"
#include<SFML/Graphics.hpp>

int main() {
    Entity entity;
    entity.name = "Test";

    World entitiesMaster;
    entitiesMaster.push_entity(&entity);

    sf::RenderWindow renderWindow(sf::VideoMode(200, 200), "SFML works!");

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
    };

    return 0;
}
