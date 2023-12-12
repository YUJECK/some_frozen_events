//
// Created by destructive_crab on 12/8/23.
//

#include "BaseRenderer.h"
#include "RendererManager.h"

void BaseRenderer::draw(IRendererComponent *drawable[], sf::RenderWindow* window) {
    double posX = 34, posY = 24;
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
        int side = 0;

        if(rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (posX - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (posX - mapX) * deltaDistX;
        }

        if(stepY < 0)
        {
            stepY = -1;
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
                std::cout << World::get_instance()->get_map()->get(mapX, mapY) << std::endl;
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

            sf::Vertex line[] =
            {
                sf::Vertex(sf::Vector2f(x * CELL_SIZE, drawStart * CELL_SIZE)),
                sf::Vertex(sf::Vector2f(x * CELL_SIZE, drawEnd * CELL_SIZE))
            };

            if(World::get_instance()->get_map()->get(mapX, mapY) == 1)
            {
                line[0].color = sf::Color::White;
                line[1].color = sf::Color::White;
            }

            if(World::get_instance()->get_map()->get(mapX, mapY) == 2)
            {
                line[0].color = sf::Color::Red;
                line[1].color = sf::Color::Red;
            }

            if(World::get_instance()->get_map()->get(mapX, mapY) == 3)
            {
                line[0].color = sf::Color::Green;
                line[1].color = sf::Color::Green;
            }

            if(World::get_instance()->get_map()->get(mapX, mapY) == 4)
            {
                line[0].color = sf::Color::Blue;
                line[1].color = sf::Color::Blue;
            }

            window->draw(line, 2, sf::Lines);
        }

    }
}