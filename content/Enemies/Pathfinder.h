//
// Created by destructive_crab on 1/14/24.
//

#ifndef SOME_FROZEN_EVENTS_PATHFINDER_H
#define SOME_FROZEN_EVENTS_PATHFINDER_H

#include <SFML/System/Vector2.hpp>
#include "PathNode.h"
#include <vector>

class Pathfinder
{
private:
    std::vector<PathNode *> get_connected(PathNode *center, const std::vector<PathNode *>& ignore);
public:
    std::vector<sf::Vector2u> get_path(sf::Vector2u start, sf::Vector2u end);

    static std::vector<sf::Vector2u> restore_path(PathNode *endNode);

    static bool check(sf::Vector2u node, std::vector<PathNode *> ignore);
};

#endif //SOME_FROZEN_EVENTS_PATHFINDER_H
