//
// Created by destructive_crab on 12/9/23.
//

#include "InputService.h"

#include "../Game.h"

InputService* InputService::instance = 0;

InputService::InputService() {
    for (int key = 0; key < KEYS_COUNT; ++key) {
        pressingData.emplace(key, 0);
    }
}

void InputService::tick() {
    for (int key = 0; key < KEYS_COUNT; ++key) {
        if(sf::Keyboard::isKeyPressed((sf::Keyboard::Key)key))
            pressingData[key]++;
        else if(pressingData[key] == -1)
            pressingData[key] = 0;
        else if(pressingData[key] > 0)
            pressingData[key] = -1;
    }

    // mousePosition = sf::Mouse::getPosition(*Game::get_instance()->get_window());
    //
    // mouseVelocity =
    //     sf::Vector2f(
    //         (int)mouse_position().x - (int)old_mousePosition.x,
    //         (int)mouse_position().y - (int)old_mousePosition.y);
    //
    // old_mousePosition = mouse_position();

    sf::Event event;
    while (Game::get_instance()->get_window()->pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            Game::get_instance()->get_window()->close();
        }

        // if(event.type == sf::Event::MouseMoved)
        // {
        //     old_mousePosition = mouse_position();
        //     mousePosition = sf::Mouse::getPosition(*Game::get_instance()->get_window());
        //
        //     sf::Vector2u size = Game::get_instance()->get_window()->getSize();
        //
        //     sf::Mouse::setPosition(
        //         sf::Vector2i(Game::get_instance()->get_window()->getPosition().x + size.x/2, Game::get_instance()->get_window()->getPosition().x + size.y/2), *Game::get_instance()->get_window());
        // }
    }

}

bool InputService::is_key_pressed(sf::Keyboard::Key key) {
    return pressingData[key] > 0;
}

bool InputService::is_key_down(sf::Keyboard::Key key) {
    return pressingData[key] == 1;
}

bool InputService::is_key_up(sf::Keyboard::Key key) {
    return pressingData[key] == -1;
}

InputService *InputService::get_instance() {
    if(instance == nullptr)
        instance = new InputService;

    return instance;
}

InputService::~InputService() {
    delete instance;
}

bool InputService::is_left_mouse_button_pressed() {
    return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

bool InputService::is_right_mouse_button_pressed() {
    return sf::Mouse::isButtonPressed(sf::Mouse::Right);
}
