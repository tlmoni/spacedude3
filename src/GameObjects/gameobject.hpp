#pragma once

#include <cmath>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "../movement.hpp"

extern sf::RenderWindow* main_window;

/* Parent class for all game objects */
class GameObject {
public:
    /* Constructor */
    GameObject(sf::Vector2f pos, std::string file);

    /* Sets position of the object and its sprite */
    void SetPosition(sf::Vector2f new_pos);

    /* Set object origin */
    void SetOrigin(float x, float y);

    /* Set object rotation */
    void SetRotation(float x, float y);

    sf::Vector2f GetPosition() { return pos_; }
    sf::Sprite& GetSprite() { return sprite_; }

private:
    // Hitbox hitbox;
    sf::Vector2f pos_; /* Variable tracking player position the scene */
    sf::Sprite sprite_; /* Variable to hold player sprite */
    sf::Texture texture_;
    // Movement movement_;
};