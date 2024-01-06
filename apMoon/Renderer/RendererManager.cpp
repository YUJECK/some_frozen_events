//
// Created by destructive_crab on 12/6/23.
//

#include "RendererManager.h"

RendererManager* RendererManager::instance = 0;

RendererManager* RendererManager::get_instance() {
    if(instance == nullptr)
        instance = new RendererManager;

    return instance;
}

RendererManager::RendererManager() {
    renderer = new Pseudo3DRenderer;
    renderWindow = World::get_instance()->get_window();
    renderWindow->setFramerateLimit(60);
}

RendererManager::~RendererManager() {
    delete renderer;
    delete instance;
}

void RendererManager::push(IRendererComponent *drawable) {
    drawables.push_back(drawable);
}

void RendererManager::erase(IRendererComponent *drawable) {
    drawables.erase(std::remove(drawables.begin(), drawables.end(), drawable));
    delete drawable;
}

void RendererManager::tick() {

    if(!std::is_sorted(drawables.begin(), drawables.end()))
        std::sort(drawables.begin(), drawables.end(), compare_decorations);

    renderer->draw(drawables.data(), drawables.size(), renderWindow);
}

RendererManager &RendererManager::operator=(RendererManager) {
    return *this;
}

void RendererManager::apply_view(sf::View *view) {
    this->view = view;
}

bool RendererManager::compare_decorations(IRendererComponent *left, IRendererComponent *right) {
    return left->get_distance_to_player() > right->get_distance_to_player();
}