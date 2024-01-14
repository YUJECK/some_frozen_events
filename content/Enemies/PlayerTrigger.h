//
// Created by destructive_crab on 1/14/24.
//

#ifndef SOME_FROZEN_EVENTS_PLAYERTRIGGER_H
#define SOME_FROZEN_EVENTS_PLAYERTRIGGER_H


#include "../../apMoon/Component.h"

class PlayerTrigger : public Component {
private:
    bool isPlayerOnTrigger;
    int fov;

public:
    bool is_triggered();

    explicit PlayerTrigger(int fov);

    ~PlayerTrigger() override;

    void start_component() override;

    void update_component() override;

    void destroy_component() override;

    bool check_trigger();
};


#endif //SOME_FROZEN_EVENTS_PLAYERTRIGGER_H
