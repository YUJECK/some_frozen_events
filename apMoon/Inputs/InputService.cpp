//
// Created by destructive_crab on 12/9/23.
//

#include "InputService.h"

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
