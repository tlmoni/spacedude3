#pragma once

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "scene.hpp"

extern sf::RenderWindow* main_window; // Allows the use of global variable main_window and its functions

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

    sf::Sprite GetSprite() { return sprite_; } // Returns player sprite

    sf::Vector2f GetPosition() {return pos_; } // Return player position


    /* UNDER CONSTRUCTION: Player sprite turning with mouse */

    sf::Vector2f GetDirection() {return direction_cursor_; } // Return mousewise direction, relative to player sprite.

    /* Function that calculates current mousewise direction, relative to player sprite */
    sf::Vector2f GetCurrentCursorDirection();

    /* UNDER CONSTRUCTION END */


private:
    sf::Vector2f pos_; // Variable tracking player position the scene
    sf::Sprite sprite_; // Variable to hold player sprite
    sf::Texture texture_basic_; // Holds player texture
    sf::Vector2u texture_size_; // Holds player sprite size

    /* UNDER CONSTRUCTION: Add variables to hold potential sprites loaded from files here */
    enum Direction {LEFT, RIGHT, UP, DOWN, DEFAULT}; // KEYBAORD: Enumerator for directions
    int direction_; // KEYBOARD: Holds current direction the player sprite is facing towards
    sf::Vector2f direction_cursor_; // MOUSE: Holds mousewise direction, relative to player sprite
    unsigned int sprint_duration_;
    /* UNDER CONSTRUCTION END */

};