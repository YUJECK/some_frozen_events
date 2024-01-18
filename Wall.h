//
// Created by destructive_crab on 12/10/23.
//

#ifndef SOME_FROZEN_EVENTS_WALL_H
#define SOME_FROZEN_EVENTS_WALL_H

#include "apMoon/Entity.h"

class Wall : public Entity {
private:
    std::string pathToImage;

public:
    Wall(std::string path);

    void start_entity() override;
    void update_entity() override;
    void destroy_entity() override;
};


#endif //SOME_FROZEN_EVENTS_WALL_H
