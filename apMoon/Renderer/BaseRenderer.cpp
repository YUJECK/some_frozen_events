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
    posX = World::get_instance()->get_player_pos().x;
    posY = World::get_instance()->get_player_pos().y;

    double rotationAngle = World::get_instance()->get_player()->get_rotation() - prevAngle;

    if (rotationAngle != 0) { //rotating
        dirX = cos(World::get_instance()->get_player()->get_rotation() * (PI / 180));
        dirY = sin(World::get_instance()->get_player()->get_rotation() * (PI / 180));

        //perpendicular to dirs
        planeX = cos(World::get_instance()->get_player()->get_rotation() * (PI / 180) + 90);
        planeY = sin(World::get_instance()->get_player()->get_rotation() * (PI / 180) + 90);
    }

    for (int x = 0; x < MAP_WIDTH * CELL_SIZE; x++) {

        double cameraX = 2 * x / double(MAP_WIDTH * CELL_SIZE) - 1;

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

            hit = World::get_instance()->get_map()->get(mapX/CELL_SIZE, mapY/CELL_SIZE);

            if (drawMode == DRAW_MAP) //draw rays
            {
                sf::RectangleShape *rectangleShape = new sf::RectangleShape(
                        sf::Vector2f(1, 1));
                rectangleShape->setPosition(mapX , mapY );

                window->draw(*rectangleShape);

                delete rectangleShape;
            }
        }

        if (side == 0) {
            perpWallDist = sideDistX - deltaDistX;
        } else {
            perpWallDist = sideDistY - deltaDistY;
        }

        int lineHeight = (int) (MAP_HEIGHT*CELL_SIZE / perpWallDist);

        int drawStart = -lineHeight / 2 + MAP_HEIGHT*CELL_SIZE / 2;

        if (drawStart < 0) {
            drawStart = 0;
        }

        int drawEnd = lineHeight / 2 + MAP_HEIGHT*CELL_SIZE / 2;

        if (drawEnd >= MAP_HEIGHT*CELL_SIZE) {
            drawEnd = MAP_HEIGHT*CELL_SIZE - 1 * CELL_SIZE;
        }

        MapCell* mapCell = World::get_instance()->get_map()->get_cell(mapX / CELL_SIZE, mapY / CELL_SIZE);

        double wallX;

        if(side == 0)
        {
            wallX = posY + perpWallDist * rayDirY;
        }
        else
        {
            wallX = posX + perpWallDist + rayDirX;
        }
        wallX -= floor(wallX);

        int texX = int(wallX * double(CELL_SIZE));

        if(side == 0 && rayDirX > 0)
        {
            texX = CELL_SIZE - texX - 1;
        }
        if(side == 1 && rayDirY < 0)
        {
            texX = CELL_SIZE - texX - 1;
        }

        double step = 1.0 * CELL_SIZE / lineHeight;
        double texPos = (drawStart - WINDOW_HEIGHT / 2 + lineHeight / 2) * step;

        for (int y = drawStart; y < drawEnd; ++y) {
            int texY = (int)texPos & (CELL_SIZE - 1);
            texPos += step;
            sf::Color color = mapCell->get_texture()->copyToImage().getPixel(texX, texY);

            buffer[y][x] = color;
        }
    }

    if (drawMode == DRAW_3D)
    { // drawing 3d render
        draw_buffer(window);

        for (int yClear = 0; yClear < WINDOW_HEIGHT; ++yClear) {
            for (int xClear = 0; xClear < WINDOW_WIDTH; ++xClear) {
                buffer[yClear][xClear] = sf::Color(0,0,0,0);
            }
        }
    }
    if(drawMode == DRAW_MAP)
    { //drawing all objects from global pool
        for (int i = 0; i < drawablesCount; ++i) {
            window->draw(*drawables[i]->get_drawable());
        }
    }
    if (InputService::get_instance()->is_key_down(sf::Keyboard::Space))
        drawMode *= -1;

    prevAngle = World::get_instance()->get_player()->get_rotation();
}

void BaseRenderer::draw_line(Stripe stripe, sf::RenderWindow* window) {
    double xScale =  (double) WINDOW_WIDTH / (double) (MAP_WIDTH*CELL_SIZE);
    double yScale =  (double) WINDOW_HEIGHT / (double) (MAP_HEIGHT*CELL_SIZE);

    sf::RectangleShape* line = new sf::RectangleShape;

    line->setSize(sf::Vector2f(1 * xScale, (stripe.yEnd - stripe.yStart) * yScale));
    line->setPosition(stripe.x * xScale, stripe.yStart * yScale);

    std::cout << line->getPosition().x << " " << line->getPosition().y << std::endl;

    switch (stripe.wallIndex) {
        case 1:
            line->setFillColor(sf::Color::White);
            break;
        case 2:
            line->setFillColor(sf::Color::Red);
            break;
        case 3:
            line->setFillColor(sf::Color::Green);
            break;
        case 4:
            line->setFillColor(sf::Color::Blue);
            break;
    }

    int resDist = ((int) stripe.dist / 20);

    if (resDist > 0) {
        line->setFillColor(sf::Color(line->getFillColor().r / resDist,
                                      line->getFillColor().g / resDist,
                                      line->getFillColor().b / resDist));
    }


    if (stripe.side == 1) {
        line->setFillColor(sf::Color(line->getFillColor().r / 2,
                                      line->getFillColor().g / 2,
                                      line->getFillColor().b / 2));
    }
    window->draw(*line);
}

double BaseRenderer::dist(double playerX, double playerY, double hitX, double hitY) {
    double  x = hitX - playerX;
    double  y = hitY - playerY;

    return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
}

void BaseRenderer::draw_buffer(sf::RenderWindow *window) {

    sf::Texture* screen = new sf::Texture;
    screen->create(WINDOW_WIDTH, WINDOW_HEIGHT);

    screen->update(reinterpret_cast<const sf::Uint8 *>(buffer));

    sf::Sprite * sprite = new sf::Sprite();
    sprite->setTexture(*screen);

    window->draw(*sprite);

    delete sprite;
}
