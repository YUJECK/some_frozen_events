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

    auto connectedTemp = get_connected(current, visited);
    toVisit.insert(toVisit.end(), connectedTemp.begin(), connectedTemp.end());

    int test = 0;

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

        //std::cout << current->x << " " << current->y << std::endl;
    }


    return std::vector<sf::Vector2u>();
}

std::vector<PathNode *> Pathfinder::get_connected(PathNode *center, std::vector<PathNode *> ignore) {
    std::vector<PathNode*> connected;
    std::vector<PathNode*> connectedResult;

    connected.push_back(new PathNode(center->x - 1, center->y + 1, center));
    connected.push_back(new PathNode(center->x + 1, center->y - 1, center));
    connected.push_back(new PathNode(center->x + 1, center->y + 1, center));
    connected.push_back(new PathNode(center->x - 1, center->y - 1, center));
    connected.push_back(new PathNode(center->x, center->y + 1, center));
    connected.push_back(new PathNode(center->x, center->y - 1, center));
    connected.push_back(new PathNode(center->x + 1, center->y, center));
    connected.push_back(new PathNode(center->x - 1, center->y, center));

    for (int i = 0; i < 8; ++i) {

        if(Game::get_instance()->get_map()->get(connected[i]->x, connected[i]->y) == 0 && check(connected[i], ignore))
        {
            connectedResult.push_back(connected[i]);
            continue;
        }

        delete connected[i];
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

    return path;
}

bool Pathfinder::check(PathNode *node, std::vector<PathNode *> ignore) {
    for (int i = 0; i < ignore.size(); ++i) {
        if(node->x == ignore[i]->x && node->y == ignore[i]->y)
            return false;
    }

    return true;
}
