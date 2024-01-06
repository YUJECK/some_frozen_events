//
// Created by destructive_crab on 12/10/23.
//

#include "WorldMap.h"
#include "Renderer/RendererManager.h"
#include "../Wall.h"

WorldMap::WorldMap(sf::Image image) {

    for (int x = 0; x < UP_MAP_WIDTH; ++x) {
        for (int y = 0; y < UP_MAP_HEIGHT; ++y) {
            map[x][y] = process_color(image.getPixel(x, y));

            if(map[x][y]->is_decoration())
            {
                Wall * wall = new Wall(map[x][y]->get_tex_path());
                wall->set_position(x, y);
                World::get_instance()->push_entity(wall);
            }
        }
    }
}

WorldMap::~WorldMap() {

    for (int x = 0; x < UP_MAP_WIDTH; ++x) {
        for (int y = 0; y < UP_MAP_HEIGHT; ++y) {
            delete map[x][y];
        }
    }
}

MapCell * WorldMap::process_color(sf::Color color) {
    MapCell* cell;

    const char* path0 = "";
    const char* path1 = "D:\\VS PROJECTS\\C++\\sfe\\some_frozen_events-curr-\\Assets\\1.png";
    const char* path2 = "D:\\VS PROJECTS\\C++\\sfe\\some_frozen_events-curr-\\Assets\\2.png";
    const char* path3 = "D:\\VS PROJECTS\\C++\\sfe\\some_frozen_events-curr-\\Assets\\3.png";
    const char* path4 = "D:\\VS PROJECTS\\C++\\sfe\\some_frozen_events-curr-\\Assets\\4.png";

    if(color == sf::Color(0, 0, 0, 0))
        cell = new MapCell(0, path0, false);
    if(color == sf::Color::White)
        cell = new MapCell(1, path1, false);
    if(color == sf::Color::Red)
        cell = new MapCell(2, path2, false);
    if(color == sf::Color::Green)
        return new MapCell(3, path3, false);
    if(color == sf::Color::Blue)
        cell = new MapCell(4, path4, true);

    return cell;
}

int WorldMap::get(unsigned int x, unsigned int y) {
    if(x >= MAP_WIDTH) return 0;
    if(y >= MAP_HEIGHT) return 0;

    return map[x][y]->get_index();
}

MapCell * WorldMap::get_cell(unsigned int x, unsigned int y) {
    return map[x][y];
}

void WorldMap::replace(unsigned int x, unsigned int y, MapCell *to) {
    if(x != 0 && y != 0 && x != MAP_WIDTH - 1 && y != MAP_HEIGHT - 1)
    {
        delete map[x][y];
        map[x][y] = to;
    }
}

void WorldMap::swap(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2) {
    MapCell* tmp;

    tmp = map[x1][y1];
    map[x1][y1] = map[x2][y2];
    map[x2][y2] = tmp;
}

RayData WorldMap::raycast(sf::Vector2u position, sf::Vector2f direction) {
    double sideDistX;
    double sideDistY;

    double deltaDistX = std::abs(1 / direction.x);
    double deltaDistY = std::abs(1 / direction.y);

    int mapX = position.x;
    int mapY = position.y;

    int stepX;
    int stepY;

    MapCell * hit = 0;

    if (direction.x < 0) {
        stepX = -1;
        sideDistX = (position.x - mapX) * deltaDistX;
    }
    else {
        stepX = 1;
        sideDistX = (mapX + 1.0 - position.x) * deltaDistX;
    }

    if (direction.y < 0) {
        stepY = -1;
        sideDistY = (position.y - mapY) * deltaDistY;
    }
    else {
        stepY = 1;
        sideDistY = (mapY + 1.0 - position.y) * deltaDistY;
    }

    //DDA
    while (hit == nullptr || hit->get_index() == 0) {
        if (sideDistX < sideDistY) {
            sideDistX += deltaDistX;
            mapX += stepX;
        } else {
            sideDistY += deltaDistY;
            mapY += stepY;
        }

        hit = World::get_instance()->get_map()->get_cell(mapX, mapY);
    }


    return RayData(hit, sf::Vector2u(mapX, mapY));
}
