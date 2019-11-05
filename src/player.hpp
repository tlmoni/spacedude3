#pragma once

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "scene.hpp"

/* Allows the use of global variable main_window and its functions */
extern sf::RenderWindow* main_window;

class Player {
public:
    /* Constructor takes in Vector2f template class for manipulating 2-dimensional vectors (Position on the grid) */
    Player(sf::Vector2f pos);

    /* Default destructor */
    ~Player() = default;

    /* Function to handle player movement and events and update them to the scene */
    void Loop();

    /* Function handling keypress and their effects on player character */
    bool Action();

    /* Function resposible for updating player character position */
    void Move(sf::Vector2f pos_dif);

    /* Function returns player sprite */
    sf::RectangleShape GetSprite() { return sprite_; }

private:
    sf::Vector2f pos_; /* Variable tracking player position the scene */
    sf::RectangleShape sprite_; /* Variable to hold player sprite */
    
    /* TODO: Add variables to hold potential sprites loaded from files here */
};