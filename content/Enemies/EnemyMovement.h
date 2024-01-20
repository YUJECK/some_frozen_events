//
// Created by destructive_crab on 1/14/24.
//

#ifndef SOME_FROZEN_EVENTS_ENEMYMOVEMENT_H
#define SOME_FROZEN_EVENTS_ENEMYMOVEMENT_H


#include "../../apMoon/Component.h"
#include "PlayerTrigger.h"
#include "Pathfinder.h"

class EnemyMovement : public Component{
private:
    std::vector<sf::Vector2u> currentPath;
    PlayerTrigger* playerTrigger;
    Pathfinder pathfinder;
    bool test = false;
    int test2 = 0;
    std::vector<sf::Vector2u> path;

public:
    ~EnemyMovement() override;

    void start_component() override;

    void update_component() override;

    void destroy_component() override;
};


#endif //SOME_FROZEN_EVENTS_ENEMYMOVEMENT_H
