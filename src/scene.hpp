#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "eventhandler.hpp"
#include "gameworld.hpp"



class Scene {
public:
    Scene(sf::RenderWindow* window);
    ~Scene();

    void ProcessEvents(sf::Event& event);

    void Init();
    void End();
    void Loop();
    void Update();

private:
    sf::RenderWindow* window_;
    EventHandler event_handler_;
    GameWorld game_world_;
};