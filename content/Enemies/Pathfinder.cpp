//
// Created by destructive_crab on 1/14/24.
//

#include "Pathfinder.h"
#include "../../apMoon/Game.h"
#include "PathNode.h"

std::vector<sf::Vector2u> Pathfinder::get_path(sf::Vector2u start, sf::Vector2u end) {
    std::vector<PathNode*> visited;
    std::vector<PathNode*> toVisit;

    PathNode* current = new PathNode(start.x, start.y, nullptr);

    std::vector<PathNode*> connectedTemp = get_connected(current, visited);
    toVisit.insert(toVisit.end(), connectedTemp.begin(), connectedTemp.end());

    while (toVisit.size() > 0)
    {
        current = toVisit.front();

        if(current->x == end.x && current->y == end.y)
        {
            std::vector<sf::Vector2u> path = restore_path(current);

            for (int i = 0; i < visited.size(); ++i) {
                delete visited[i];
            }

            delete current;

            return path;
        }

        connectedTemp = get_connected(current, visited);
        
        toVisit.insert(toVisit.end(), connectedTemp.begin(), connectedTemp.end());

        visited.push_back(current);
        toVisit.erase(toVisit.begin());
    }

    return std::vector<sf::Vector2u>();
}

std::vector<PathNode *> Pathfinder::get_connected(PathNode *center, const std::vector<PathNode *>& ignore) {
    std::vector<sf::Vector2u> connected;
    std::vector<PathNode*> connectedResult;

    connected.push_back(sf::Vector2u(center->x, center->y + 1));
    connected.push_back(sf::Vector2u(center->x, center->y - 1));
    connected.push_back(sf::Vector2u(center->x + 1, center->y));
    connected.push_back(sf::Vector2u(center->x - 1, center->y));

    connected.push_back(sf::Vector2u(center->x+1, center->y + 1));
    connected.push_back(sf::Vector2u(center->x + 1, center->y - 1));
    connected.push_back(sf::Vector2u(center->x - 1, center->y + 1));
    connected.push_back(sf::Vector2u(center->x - 1, center->y -1));

    for (int i = 0; i < 4; ++i) {

        if(Game::get_instance()->get_map()->get(connected[i].x, connected[i].y) == 0 && check(connected[i], ignore))
        {
            connectedResult.push_back(new PathNode(connected[i].x, connected[i].y, center));
        }
    }

    return connectedResult;
}

std::vector<sf::Vector2u> Pathfinder::restore_path(PathNode *endNode) {
    std::vector<sf::Vector2u> path;
    PathNode * current = endNode;

    while (current->prev)
    {
        path.push_back(sf::Vector2u(current->x, current->y));
        current = current->prev;
    }

    std::reverse(std::begin(path), std::end(path));
    path.erase(path.begin());

    return path;
}

bool Pathfinder::check(sf::Vector2u node, std::vector<PathNode *> ignore) {
    for (int i = 0; i < ignore.size(); ++i) {
        if(node.x == ignore[i]->x && node.y == ignore[i]->y)
            return false;
    }

    return true;
}
