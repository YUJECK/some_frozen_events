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
    sf::Vector2f mouseVelocity;
    sf::Vector2i mousePosition;
    sf::Vector2i old_mousePosition;

public:
    InputService();
    ~InputService();

    static InputService* get_instance();

    sf::Vector2f mouse_velocity() const
    {
        return mouseVelocity;
    }

    sf::Vector2i mouse_position() const
    {
        return mousePosition;
    }

    void tick();

    bool is_key_pressed(sf::Keyboard::Key key);
    bool is_key_down(sf::Keyboard::Key key);
    bool is_key_up(sf::Keyboard::Key key);
    bool is_left_mouse_button_pressed();

    bool is_right_mouse_button_pressed();
};


#endif //SOME_FROZEN_EVENTS_INPUTSERVICE_H
