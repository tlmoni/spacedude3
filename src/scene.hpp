#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "inputhandler.hpp"



class Scene {
public:
    Scene(sf::RenderWindow* window);
    ~Scene();

    void ProcessEvents(sf::Event& event);

    void HandlePlayerInput();

    void Init();
    void End();
    void GameLoop();

private:
    sf::RenderWindow* window_;
    InputHandler input_;

};