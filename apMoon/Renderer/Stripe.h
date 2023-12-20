//
// Created by destructive_crab on 12/20/23.
//

#ifndef SOME_FROZEN_EVENTS_STRIPE_H
#define SOME_FROZEN_EVENTS_STRIPE_H


class Stripe {

public:
    Stripe(int x, int yStart, int yEnd, int wallIndex, double dist, int side);

public:
    int x;
    int yStart;
    int yEnd;
    double dist;
    int side;
    int wallIndex;
};


#endif //SOME_FROZEN_EVENTS_STRIPE_H
