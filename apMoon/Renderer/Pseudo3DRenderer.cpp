//
// Created by destructive_crab on 12/8/23.
//

#include "Pseudo3DRenderer.h"
#include "RendererManager.h"
#include "../Inputs/InputService.h"
#include<math.h>

Pseudo3DRenderer::Pseudo3DRenderer()
{
    PIby180 = PI / 180;

    WINDOW_WIDTH = World::get_instance()->get_window()->getSize().x;
    WINDOW_HEIGHT = World::get_instance()->get_window()->getSize().y;

    buffer = new sf::Image;
    buffer->create(WINDOW_WIDTH, WINDOW_HEIGHT);

    screen_tex = new sf::Texture;
    screen_tex->create(WINDOW_WIDTH, WINDOW_HEIGHT);

    screen_spr = new sf::Sprite;
    screen_spr->setTexture(*screen_tex);
}

Pseudo3DRenderer::~Pseudo3DRenderer() {
    delete [] buffer;
    delete screen_tex;
    delete screen_spr;
}

void Pseudo3DRenderer::draw(IRendererComponent *drawables[], int drawablesCount, sf::RenderWindow* window) {
    posX = World::get_instance()->get_player_pos().x;
    posY = World::get_instance()->get_player_pos().y;

    float angle = World::get_instance()->get_player()->get_rotation();

    double rotationAngle = angle - prevAngle;

    if (rotationAngle != 0) { //rotating
        dirX = cos(angle * PIby180);
        dirY = sin(angle * PIby180);

        //perpendicular to dirs
        planeX = cos(angle * PIby180 + 90);
        planeY = sin(angle * PIby180 + 90);
    }

    for (int x = 0; x < WINDOW_WIDTH; x++) {
        double cameraX = 2 * x / double(WINDOW_WIDTH) - 1;

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

        MapCell * hit = 0;
        int side;

        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (posX - mapX) * deltaDistX;
        }
        else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - posX) * deltaDistX;
        }

        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (posY - mapY) * deltaDistY;
        }
        else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - posY) * deltaDistY;
        }

        //DDA
        while (hit == nullptr || hit->get_index() == 0) {
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }

            hit = World::get_instance()->get_map()->get_cell(mapX, mapY);
        }

        if (side == 0) {
            perpWallDist = sideDistX - deltaDistX;
        }
        else {
            perpWallDist = sideDistY - deltaDistY;
        }

        int lineHeight = (int) (WINDOW_HEIGHT / perpWallDist);

        int drawStart = -lineHeight / 2 + WINDOW_HEIGHT / 2;

        if (drawStart < 0) {
            drawStart = 0;
        }

        int drawEnd = lineHeight / 2 + WINDOW_HEIGHT / 2;

        if (drawEnd >= WINDOW_HEIGHT) {
            drawEnd = WINDOW_HEIGHT - 1;
        }

        //setting up textures
        double wallX;

        if(side == 0)
        {
            wallX = posY + perpWallDist * rayDirY;
        }
        else
        {
            wallX = posX + perpWallDist * rayDirX;
        }
        wallX -= floor(wallX);

        int texX = int(wallX * double(CELL_SIZE));

        if(side == 0 && rayDirX > 0)
        {
            texX = CELL_SIZE - texX - 1;
        }
        else if(side == 1 && rayDirY < 0)
        {
            texX = CELL_SIZE - texX - 1;
        }

        double step = 1.0 * CELL_SIZE / lineHeight;
        double texPos = (drawStart - WINDOW_HEIGHT / 2 + lineHeight / 2) * step;

        for (int y = drawStart; y < drawEnd; y++) {
            int texY = (int)texPos & (CELL_SIZE - 1);
            texPos += step;

            sf::Color color = hit->get_pixel(texX, texY);

            color = process_color(color, side);

            buffer->setPixel(x, y, color);
        }
    }

    // drawing result buffer
    draw_buffer(window);

    //clear buffer
    for (int x = 0; x < WINDOW_WIDTH; x++){
        for (int y = 0; y < WINDOW_HEIGHT; ++y) {
            buffer->setPixel(x, y, sf::Color(0, 0, 0, 0));
        }
    }

    prevAngle = World::get_instance()->get_player()->get_rotation();
}

void Pseudo3DRenderer::draw_buffer(sf::RenderWindow *window) {
    screen_tex->update(*buffer);
    window->draw(*screen_spr);
}

sf::Color Pseudo3DRenderer::process_color(sf::Color color, int side) {
    if(side == 1)
        return sf::Color(color.r / 2, color.g / 2, color.b / 2);

    return color;
}
