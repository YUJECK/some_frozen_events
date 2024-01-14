//
// Created by destructive_crab on 1/14/24.
//

#include <iostream>
#include "PathNode.h"

PathNode::PathNode(unsigned int x, unsigned int y, PathNode *prev)
: x(x), y(y), prev(prev) {}

bool PathNode::operator==(const PathNode &rhs) {
    return this->x == rhs.x && this->y == rhs.y;
}

bool PathNode::operator!=(const PathNode &rhs) {
    return this->x != rhs.x && this->y != rhs.y;
}
