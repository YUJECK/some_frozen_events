//
// Created by destructive_crab on 12/20/23.
//

#ifndef SOME_FROZEN_EVENTS_STRIPE_H
#define SOME_FROZEN_EVENTS_STRIPE_H


class Stripe {

public:
    Stripe(int x, int yStart, int yEnd, int wallIndex, double dist);

public:
    int x;
    int yStart;
    int yEnd;
    int wallIndex;
    double dist;
};


#endif //SOME_FROZEN_EVENTS_STRIPE_H
