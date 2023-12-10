//
// Created by destructive_crab on 12/6/23.
//

#ifndef SOME_FROZEN_EVENTS_TESTENTITY_H
#define SOME_FROZEN_EVENTS_TESTENTITY_H

#include "apMoon/Entity.h"

class TestEntity : public Entity {
private:
    sf::View *view;
public:
    void start_entity() override;

    void update_entity() override;

    void destroy_entity() override;
};

#endif //SOME_FROZEN_EVENTS_TESTENTITY_H
