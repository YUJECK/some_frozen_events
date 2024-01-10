//
// Created by User on 06.01.2024.
//

#ifndef SOME_FROZEN_EVENTS_PLAYERHUD_H
#define SOME_FROZEN_EVENTS_PLAYERHUD_H


#include "../apMoon/GUI/GUILevel.h"

class PlayerHUD : public GUILevel {
protected:
    void apply_transform() override;

public:
    PlayerHUD(const sf::Vector2f &position, const sf::Vector2f &scale);

    void on_update() override;

    void on_pushed() override;

    bool targetable() override;
};


#endif //SOME_FROZEN_EVENTS_PLAYERHUD_H
