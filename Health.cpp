//
// Created by User on 06.01.2024.
//

#include "Health.h"

void Health::start_component() {

}

void Health::update_component() {

}

void Health::destroy_component() {

}

int Health::current() {
    return health;
}

bool Health::hit(int health) {
    if(health <= 0)
        return false;

    this->health -= health;

    if(current() <= 0)
    {
        die();
        return true;
    }
    return false;

}

void Health::heal(int health) {
    if(health <= 0)
        return;

    this->health += health;
}
