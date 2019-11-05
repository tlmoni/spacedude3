#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "player.hpp"

extern sf::RenderWindow* main_window;

class Scene {
public:
    Scene();
    ~Scene();

    void Init();
    void End();
    void Update();
    void Render();

private:
    // std::vector<GameObject*> objects_;
    // std::vector<Player*> players_;
};