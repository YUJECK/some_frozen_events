//
// Created by destructive_crab on 12/8/23.
//

#ifndef SOME_FROZEN_EVENTS_BASERENDERER_H
#define SOME_FROZEN_EVENTS_BASERENDERER_H

#include "RendererMethod.h"
#include "../World.h"
#include "Stripe.h"
#include "RendererManager.h"

class BaseRenderer : public RendererMethod
{
private:
    void draw_line(Stripe stripe, sf::RenderWindow* window);
    void draw_buffer(sf::RenderWindow* window);

    double dist(double playerX, double playerY, double hitX, double hitY);
    int drawMode = 1;

    float prevAngle = 0;

    sf::Color buffer[WINDOW_HEIGHT][WINDOW_WIDTH];
    float posX;

    float posY;
    double dirX = 1;

    double dirY = 1;
    double planeX = 0.9;
    double planeY = 0.66;

public:
    void draw(IRendererComponent *drawables[],  int drawablesCount, sf::RenderWindow* window) override;
};


#endif //SOME_FROZEN_EVENTS_BASERENDERER_H
