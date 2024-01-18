//
// Created by destructive_crab on 12/10/23.
//

#include "Wall.h"
#include "apMoon/Renderer/SpriteRenderer.h"

Wall::Wall(std::string path) {
    pathToImage = path;
}

void Wall::start_entity() {
    add_component(new SpriteRenderer(pathToImage));
}

void Wall::update_entity() {

}

void Wall::destroy_entity() {

}
