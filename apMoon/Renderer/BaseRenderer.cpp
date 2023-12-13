//
// Created by destructive_crab on 12/8/23.
//

#include "BaseRenderer.h"
#include "RendererManager.h"
#include "../Inputs/InputService.h"

void BaseRenderer::draw(IRendererComponent *drawables[], int drawablesCount, sf::RenderWindow* window) {
    if(!window1)
        window1 = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML not works!!");;

    double posX = World::get_instance()->get_player_pos().x / CELL_SIZE, posY = World::get_instance()->get_player_pos().y / CELL_SIZE;
    double dirX = -1, dirY = 0;
    double planeX = 0, planeY = 0.66;

    for (int x = 0; x < MAP_WIDTH; x++)
    {
        double cameraX = 2 * x / double (MAP_WIDTH) - 1;
        double rayDirX = dirX + planeX * cameraX;
        double rayDirY = dirY + planeY * cameraX;

        int mapX = int(posX);
        int mapY = int(posY);

        double sideDistX;
        double sideDistY;

        double deltaDistX = std::abs(1/rayDirX);
        double deltaDistY = std::abs(1/rayDirY);

        double perpWallDist;

        int stepX;
        int stepY;

        int hit = 0;
        int side;

        if(rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (posX - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - posX) * deltaDistX;
        }

        if(rayDirY < 0)
        {
            stepY = 1;
            sideDistY = (posY - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - posY) * deltaDistY;
        }

        while(hit == 0)
        {
            if(sideDistX < sideDistY)
            {
                sideDistX += deltaDistY;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }

            if(World::get_instance()->get_map()->get(mapX, mapY) > 0)
            {
                hit = 1;
            }

            if(side == 0)
            {
                perpWallDist = sideDistX - deltaDistX;
            }
            else
            {
                perpWallDist = sideDistY - deltaDistY;
            }

            int lineHeight = (int)(MAP_HEIGHT / perpWallDist);

            int drawStart = -lineHeight / 2 + MAP_HEIGHT / 2;

            if(drawStart < 0)
                drawStart = 0;

            int drawEnd = lineHeight / 2 + MAP_HEIGHT / 2;

            if(drawEnd >= MAP_HEIGHT)
            {
                drawEnd = MAP_HEIGHT - 1;
            }

            drawLine(x, drawStart, drawEnd, window);
        }

        for (int i = 0; i < drawablesCount; ++i) {
            window1->draw(*drawables[i]->get_drawable());
        }
    }
}

void BaseRenderer::drawLine(int x, int y1, int y2, sf::RenderWindow * window) {

    sf::RectangleShape* shape = new sf::RectangleShape;
    shape->setSize(sf::Vector2f(CELL_SIZE, (y2-y1) * CELL_SIZE));
    shape->setPosition(x * CELL_SIZE, y1 * CELL_SIZE);

//    if(InputService::get_instance()->is_key_down(sf::Keyboard::Space))
//    {
//        std::cout << "x: " << x << " x2: " << x2 << std::endl;
//        std::cout << "y1: " << y1 << " y2: " << y2 << std::endl;
//    }

    window->draw(*shape);

    delete shape;
}
