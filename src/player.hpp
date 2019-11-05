#pragma once

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "scene.hpp"



extern sf::RenderWindow* main_window;

class Player {
public:
    Player(sf::Vector2f pos);
    ~Player() = default;

    void Loop();

    bool Action();
    void Move(sf::Vector2f pos_dif);

    sf::RectangleShape GetSprite() { return sprite_; }

private:
    sf::Vector2f pos_;
    sf::RectangleShape sprite_;

};