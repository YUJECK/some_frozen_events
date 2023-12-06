//
// Created by destructive_crab on 12/6/23.
//

#ifndef FREEZINGNOSE_TESTCOMPONENT_H
#define FREEZINGNOSE_TESTCOMPONENT_H


#include "apMoon/Component.h"

class TestComponent : public Component{
    void destroy_component() override;
    void start_component() override;
    void update_component() override;
};


#endif //FREEZINGNOSE_TESTCOMPONENT_H
