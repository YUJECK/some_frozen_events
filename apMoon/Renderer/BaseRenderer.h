//
// Created by destructive_crab on 12/8/23.
//

#ifndef SOME_FROZEN_EVENTS_BASERENDERER_H
#define SOME_FROZEN_EVENTS_BASERENDERER_H

#include "RendererMethod.h"
#include "../World.h"

class BaseRenderer : public RendererMethod
{
private:
    void drawLine(int x, int y1, int y2, sf::RenderWindow *window, int wallinx, int side, int i, int i1,
                  sf::Vector2<float> vector2);

    double dist(double x1, double y1, double x2, double y2);

    sf::RenderWindow* window1;

    int a = 1;
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
