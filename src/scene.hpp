#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "eventhandler.hpp"
#include "gameworld.hpp"

/* Description here */
class Scene {
public:
    /* Description here */
    Scene(sf::RenderWindow* window);

    /* Description here */
    ~Scene();

    /* Description here */
    void ProcessEvents(sf::Event& event);

    /* Description here */
    void Init();

    /* Description here */
    void End();

    /* Description here */
    void Loop();

    /* Description here */
    void Update();

private:
    sf::RenderWindow* window_;
    EventHandler event_handler_;
    GameWorld game_world_;
};
