//
// Created by destructive_crab on 12/8/23.
//

#include "BaseRenderer.h"
#include "RendererManager.h"
#include "../Inputs/InputService.h"
#include "Stripe.h"
#include<math.h>

#define PI 3.14159265359
#define DRAW_MAP -1
#define DRAW_3D 1

void BaseRenderer::draw(IRendererComponent *drawables[], int drawablesCount, sf::RenderWindow* window) {
    posX = World::get_instance()->get_player_pos().x / CELL_SIZE;
    posY = World::get_instance()->get_player_pos().y / CELL_SIZE;

    double rotationAngle = World::get_instance()->get_player()->get_rotation() - prevAngle;

    if (rotationAngle != 0) { //rotating
        dirX = cos(World::get_instance()->get_player()->get_rotation() * (PI / 180));
        dirY = sin(World::get_instance()->get_player()->get_rotation() * (PI / 180));

        //perpendicular to dirs
        planeX = cos(World::get_instance()->get_player()->get_rotation() * (PI / 180) + 90)/1.5;
        planeY = sin(World::get_instance()->get_player()->get_rotation() * (PI / 180) + 90)/1.5;
    }

    Stripe* prevStripe = 0 ;
    for (int x = 0; x < MAP_WIDTH; x++) {

        double cameraX = 2 * x / double(MAP_WIDTH) - 1;

        double rayDirX = dirX + planeX * cameraX;
        double rayDirY = dirY + planeY * cameraX;

        int mapX = int(posX);
        int mapY = int(posY);

        double sideDistX;
        double sideDistY;

        double deltaDistX = std::abs(1 / rayDirX);
        double deltaDistY = std::abs(1 / rayDirY);

        double perpWallDist;

        int stepX;
        int stepY;

        int hit = 0;
        int side;

        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (posX - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - posX) * deltaDistX;
        }

        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (posY - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - posY) * deltaDistY;
        }

        //DDA
        while (hit == 0) {
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }

            hit = World::get_instance()->get_map()->get(mapX, mapY);

            if (drawMode == DRAW_MAP) //draw raycasts
            {
                sf::RectangleShape *rectangleShape = new sf::RectangleShape(
                        sf::Vector2f(1 * CELL_SIZE / 2, 1 * CELL_SIZE / 2));
                rectangleShape->setPosition(mapX * CELL_SIZE, mapY * CELL_SIZE);

                window->draw(*rectangleShape);

                delete rectangleShape;
            }
        }

        if (side == 0) {
            perpWallDist = sideDistX - deltaDistX;
        } else {
            perpWallDist = sideDistY - deltaDistY;
        }

        int lineHeight = (int) (MAP_HEIGHT / perpWallDist);

        int drawStart = -lineHeight / 2 + MAP_HEIGHT / 2;

        if (drawStart < 0) {
            drawStart = 0;
        }

        int drawEnd = lineHeight / 2 + MAP_HEIGHT / 2;

        if (drawEnd >= MAP_HEIGHT) {
            drawEnd = MAP_HEIGHT - 1;
        }

        if (drawMode == DRAW_3D) { // drawing 3d render
            Stripe *stripe = new Stripe(x, drawStart, drawEnd, hit, dist(posX, posY, mapX, mapY), side);

            drawLine(*stripe, window, prevStripe);
            drawLine(*stripe, window, nullptr);

            if(prevStripe)
                delete prevStripe;

            prevStripe = stripe;

        } else { //drawing all objects from global pool
            for (int i = 0; i < drawablesCount; ++i) {
                window->draw(*drawables[i]->get_drawable());
            }
        }
    }

    if (InputService::get_instance()->is_key_down(sf::Keyboard::Space))
        drawMode *= -1;

    prevAngle = World::get_instance()->get_player()->get_rotation();
}

void BaseRenderer::drawLine(Stripe stripe, sf::RenderWindow* window, Stripe* prevStripe) {
    double xScale = (double) WINDOW_WIDTH / (double) (MAP_WIDTH * CELL_SIZE);
    double yScale = (double) WINDOW_HEIGHT / (double) (MAP_HEIGHT * CELL_SIZE);

    if (prevStripe == nullptr) {

        sf::RectangleShape *shape = new sf::RectangleShape;

        shape->setSize(sf::Vector2f(xScale, (stripe.yEnd - stripe.yStart) * CELL_SIZE * yScale));
        shape->setPosition(stripe.x * CELL_SIZE * xScale, stripe.yStart * CELL_SIZE * yScale);

        switch (stripe.wallIndex) {
            case 1:
                shape->setFillColor(sf::Color::White);
                break;
            case 2:
                shape->setFillColor(sf::Color::Red);
                break;
            case 3:
                shape->setFillColor(sf::Color::Green);
                break;
            case 4:
                shape->setFillColor(sf::Color::Blue);
                break;
        }

        int resDist = ((int) stripe.dist / 2);

        if (resDist > 0) {
            shape->setFillColor(sf::Color(shape->getFillColor().r / resDist,
                                          shape->getFillColor().g / resDist,
                                          shape->getFillColor().b / resDist));
        }


        if (stripe.side == 1) {
            shape->setFillColor(sf::Color(shape->getFillColor().r / 2,
                                          shape->getFillColor().g / 2,
                                          shape->getFillColor().b / 2));
        }
        window->draw(*shape);

        delete shape;

    }
    else{
        double btwYStart = prevStripe->yStart*CELL_SIZE;
        double btwYEnd = prevStripe->yEnd*CELL_SIZE;

        for (int xbtw = prevStripe->x*CELL_SIZE; xbtw < stripe.x*CELL_SIZE; xbtw++)
        {
            sf::RectangleShape *shape = new sf::RectangleShape;

            if(prevStripe->yStart > stripe.yStart && btwYStart >= stripe.yStart * CELL_SIZE)
            {
                btwYStart-=1;
                btwYEnd+=1;
            }
            else if(btwYStart <= stripe.yStart* CELL_SIZE)
            {
                btwYStart += 1;
                btwYEnd -= 1;
            }

            shape->setSize(sf::Vector2f(1* xScale, (btwYEnd - btwYStart)* yScale));
            shape->setPosition(xbtw * xScale, btwYStart * yScale);

            switch (stripe.wallIndex) {
                case 1:
                    shape->setFillColor(sf::Color::White);
                    break;
                case 2:
                    shape->setFillColor(sf::Color::Red);
                    break;
                case 3:
                    shape->setFillColor(sf::Color::Green);
                    break;
                case 4:
                    shape->setFillColor(sf::Color::Blue);
                    break;
            }

            int resDist = ((int) stripe.dist / 2);

            if (resDist > 0) {
                shape->setFillColor(sf::Color(shape->getFillColor().r / resDist,
                                              shape->getFillColor().g / resDist,
                                              shape->getFillColor().b / resDist));
            }


            if (stripe.side == 1) {
                shape->setFillColor(sf::Color(shape->getFillColor().r / 2,
                                              shape->getFillColor().g / 2,
                                              shape->getFillColor().b / 2));
            }

            window->draw(*shape);

            delete shape;

        }
    }
}

double BaseRenderer::dist(double playerX, double playerY, double hitX, double hitY) {
    double  x = hitX - playerX;
    double  y = hitY - playerY;

    return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
}