//
// Created by destructive_crab on 12/8/23.
//

#include "Pseudo3DRenderer.h"
#include<math.h>

Pseudo3DRenderer::Pseudo3DRenderer()
{
    PIby180 = PI / 180;

    ceiling_tex.loadFromFile("D:\\VS PROJECTS\\C++\\sfe\\some_frozen_events-curr-\\Assets\\ceiling.png");
    floor_tex.loadFromFile("D:\\VS PROJECTS\\C++\\sfe\\some_frozen_events-curr-\\Assets\\floor.png");

    WINDOW_WIDTH = World::get_instance()->get_window()->getSize().x;
    WINDOW_HEIGHT = World::get_instance()->get_window()->getSize().y;

    buffer = new sf::Image;
    buffer->create(WINDOW_WIDTH, WINDOW_HEIGHT);

    screen_tex = new sf::Texture;
    screen_tex->create(WINDOW_WIDTH, WINDOW_HEIGHT);

    screen_spr = new sf::Sprite;
    screen_spr->setTexture(*screen_tex);

    ZBuffer = new double [WINDOW_WIDTH];
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

    sf::Image texture;
    texture.loadFromFile("D:\\VS PROJECTS\\C++\\sfe\\some_frozen_events-curr-\\Assets\\1.png");

    //floor and ceiling

    for (int y = 0; y < WINDOW_HEIGHT; ++y) {
        float rayDirX0 = dirX - planeX;
        float rayDirX1 = dirX + planeX;

        float rayDirY0 = dirY - planeY;
        float rayDirY1 = dirY + planeY;

        int curPos = y - WINDOW_HEIGHT / 2; //текущая позиция относительно центра экрана

        float posZ = WINDOW_HEIGHT / 2; // вертикальная позиция камеры

        float rowDistance = posZ / curPos;

        float stepX = rowDistance * (rayDirX1 - rayDirX0) / WINDOW_WIDTH;
        float stepY = rowDistance * (rayDirY1 - rayDirY0) / WINDOW_WIDTH;

        float floorX = posX + rowDistance * rayDirX0;
        float floorY = posY + rowDistance * rayDirY0;

        for (unsigned int x = 0; x < WINDOW_WIDTH; ++x) { //полоска за полоской рисуем
            int cellX = floorX;
            int cellY = floorY;

            int tx = (int) (CELL_SIZE * (floorX - cellX)) & (CELL_SIZE - 1);
            int ty = (int) (CELL_SIZE * (floorY - cellY)) & (CELL_SIZE - 1);

            floorX += stepX;
            floorY += stepY;

            sf::Color color;

            //floor
            color = floor_tex.getPixel(tx, ty);

            buffer->setPixel(x, y, color);

            //ceiling
            color = ceiling_tex.getPixel(tx, ty);
            buffer->setPixel(x, WINDOW_HEIGHT - y - 1, color);
        }
    }
    //walls
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
        while (hit == nullptr || hit->get_index() == 0 || hit->is_decoration()) {
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

        ZBuffer[x] = perpWallDist;
    }

    for(int i = 0; i < drawablesCount; i++) {
        //translate sprite position to relative to camera
        double spriteX = drawables[i]->get_daddy()->get_position().x - posX;
        double spriteY = drawables[i]->get_daddy()->get_position().y - posY;

        double invDet = 1.0 / (planeX * dirY - dirX * planeY); //required for correct matrix multiplication

        double transformX = invDet * (dirY * spriteX - dirX * spriteY);
        double transformY = invDet * (-planeY * spriteX + planeX *
                                                          spriteY); //this is actually the depth inside the screen, that what Z is in 3D

        int spriteScreenX = int((WINDOW_WIDTH / 2) * (1 + transformX / transformY));

        //calculate height of the sprite on screen
        int spriteHeight = abs(
                int(WINDOW_HEIGHT / (transformY))); //using 'transformY' instead of the real distance prevents fisheye
        //calculate lowest and highest pixel to fill in current stripe
        int drawStartY = -spriteHeight / 2 + WINDOW_HEIGHT / 2;
        if (drawStartY < 0) drawStartY = 0;
        int drawEndY = spriteHeight / 2 + WINDOW_HEIGHT / 2;
        if (drawEndY >= WINDOW_HEIGHT) drawEndY = WINDOW_HEIGHT - 1;

        //calculate width of the sprite
        int spriteWidth = abs(int(WINDOW_HEIGHT / (transformY)));
        int drawStartX = -spriteWidth / 2 + spriteScreenX;
        if (drawStartX < 0) drawStartX = 0;
        int drawEndX = spriteWidth / 2 + spriteScreenX;
        if (drawEndX >= WINDOW_WIDTH) drawEndX = WINDOW_WIDTH - 1;

        //loop through every vertical stripe of the sprite on screen
        for (int stripe = drawStartX; stripe < drawEndX; stripe++) {
            int texX = int(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * CELL_SIZE / spriteWidth) / 256;

            if (transformY > 0 && stripe > 0 && stripe < WINDOW_WIDTH && transformY < ZBuffer[stripe])
                for (int y = drawStartY; y < drawEndY; y++) {
                    int d = (y) * 256 - WINDOW_HEIGHT * 128 + spriteHeight * 128;
                    int texY = ((d * CELL_SIZE) / spriteHeight) / 256;
                    sf::Color color = drawables[i]->get_image()->getPixel(texX, texY);

                    if(color != sf::Color(0,0,0,0))
                        buffer->setPixel(stripe, y, color);
                }
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