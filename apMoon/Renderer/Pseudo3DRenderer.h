//
// Created by destructive_crab on 12/8/23.
//

#ifndef SOME_FROZEN_EVENTS_PSEUDO3DRENDERER_H
#define SOME_FROZEN_EVENTS_PSEUDO3DRENDERER_H

#include "RendererMethod.h"
#include "../World.h"
#include "Stripe.h"
#include "RendererManager.h"

#define PI 3.14159265359

class Pseudo3DRenderer : public RendererMethod
{
public:
    Pseudo3DRenderer();
    ~Pseudo3DRenderer();

    void draw(IRendererComponent *drawables[],  int drawablesCount, sf::RenderWindow* window) override;

private:
    void draw_buffer(sf::RenderWindow* window);

    float prevAngle = 0;

    float posX;
    float posY;

    double dirX = 1;
    double dirY = 1;

    double planeX = 0.9;
    double planeY = 0.66;

    int WINDOW_WIDTH = 0;
    int WINDOW_HEIGHT = 0;

    sf::Uint32 buffer[768][1366];
    sf::Sprite* screen_spr;
    sf::Texture* screen_tex;

    void draw_line(int x, int y1, int y2, sf::RenderWindow *window, int wallinx, int side);
};


#endif //SOME_FROZEN_EVENTS_PSEUDO3DRENDERER_H
