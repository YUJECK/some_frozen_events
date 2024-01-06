//
// Created by destructive_crab on 12/8/23.
//

#ifndef SOME_FROZEN_EVENTS_PSEUDO3DRENDERER_H
#define SOME_FROZEN_EVENTS_PSEUDO3DRENDERER_H

#include "RendererMethod.h"
#include "../World.h"
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
    double PIby180;

    float posX;
    float posY;

    double dirX = 1;
    double dirY = 1;

    double planeX = 0.9;
    double planeY = 0.66;

    int WINDOW_WIDTH = 0;
    int WINDOW_HEIGHT = 0;

    double * ZBuffer;
    sf::Image* buffer;
    sf::Sprite* screen_spr;
    sf::Texture* screen_tex;

    sf::Image floor_tex;
    sf::Image ceiling_tex;

    sf::Color process_color(sf::Color color, int side);
};


#endif //SOME_FROZEN_EVENTS_PSEUDO3DRENDERER_H
