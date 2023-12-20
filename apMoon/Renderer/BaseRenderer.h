//
// Created by destructive_crab on 12/8/23.
//

#ifndef SOME_FROZEN_EVENTS_BASERENDERER_H
#define SOME_FROZEN_EVENTS_BASERENDERER_H

#include "RendererMethod.h"
#include "../World.h"
#include "Stripe.h"

class BaseRenderer : public RendererMethod
{
private:
    void drawLine(Stripe stripe, sf::RenderWindow* window);
    double dist(double playerX, double playerY, double hitX, double hitY);

    int drawMode = 1;
public:
    void draw(IRendererComponent *drawables[],  int drawablesCount, sf::RenderWindow* window) override;

    float prevAngle = 0;

    float posX;
    float posY;

    double dirX = 1;
    double dirY = 1;

    double planeX = 0.9;
    double planeY = 0.66;

};


#endif //SOME_FROZEN_EVENTS_BASERENDERER_H
