//
// Created by destructive_crab on 1/14/24.
//

#ifndef SOME_FROZEN_EVENTS_PATHNODE_H
#define SOME_FROZEN_EVENTS_PATHNODE_H


struct PathNode {
public:
    unsigned int x;
    unsigned int y;

    PathNode * prev;

    PathNode(unsigned int x, unsigned int y, PathNode *prev);

    bool operator==(const PathNode& rhs);

    bool operator!=(const PathNode& rhs);
};


#endif //SOME_FROZEN_EVENTS_PATHNODE_H
