#include "World.h"
#include "../TestEntity.h"

int main() {
    TestEntity testEntity;
    testEntity.name = "Test";

    World entitiesMaster;
    entitiesMaster.push_entity(&testEntity);

//    sf::RenderWindow renderWindow(sf::VideoMode(200, 200), "SFML works!");
//
//    while (renderWindow.isOpen())
//    {
//        sf::Event event;
//        while (renderWindow.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                renderWindow.close();
//        }
//
//        renderWindow.clear();
//        renderWindow.display();
//    };

    return 0;
}
