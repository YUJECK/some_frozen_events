//
// Created by destructive_crab on 12/9/23.
//

#ifndef SOME_FROZEN_EVENTS_INPUTSERVICE_H
#define SOME_FROZEN_EVENTS_INPUTSERVICE_H

#include <map>
#include <SFML/Graphics.hpp>

class InputService {
private:
    static InputService* instance;

    const int KEYS_COUNT = 256;
    std::map<int, int> pressingData;

public:
    InputService();

    static InputService* get_instance();

    void tick();

    bool is_key_pressed(sf::Keyboard::Key key);
    bool is_key_down(sf::Keyboard::Key key);
    bool is_key_up(sf::Keyboard::Key key);
};


#endif //SOME_FROZEN_EVENTS_INPUTSERVICE_H
