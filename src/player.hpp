#pragma once

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "character.hpp"
#include "scene.hpp"
#include "GameObjects/gameobject.hpp"

/* Allows the usege of global variable main_window and its functions */
extern sf::RenderWindow* main_window;


class Player : public GameObject {
public:
    /* Constructor takes in Vector2f template class for manipulating 2-dimensional vectors (Position on the grid) */
    Player(sf::Vector2f pos, std::string identity);

    /* Default destructor */
    ~Player() = default;

    /* Function to handle player movement and events and update them to the scene */
    void Loop();

    /* Function handling keypress and their effects on player character */
    bool Action();

    /* Function resposible for updating player character position */
    void Move(sf::Vector2f pos_dif);

<<<<<<< HEAD
    /* Function that calculates current mousewise direction, relative to player sprite */
    sf::Vector2f GetCurrentCursorDirection();

=======
    sf::Sprite GetSprite() { return sprite_; } // Returns player sprite

    sf::Vector2f GetPosition() { return pos_; } // Return player position


    /* UNDER CONSTRUCTION: Player sprite turning with mouse & viewpoint control */

    sf::Vector2f GetDirection() { return direction_cursor_; } // Return mousewise direction, relative to player sprite.

    sf::View GetView() { return player_cam_; } // Return player camera position.

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

    sf::View player_cam_; // Player view of the game
    /* UNDER CONSTRUCTION END */
>>>>>>> 0431a975086571bf32a2a896f8304bd3ce35f5d8

private:
    // Character character_;
    sf::View player_cam_;
    sf::Vector2f direction_cursor_; // MOUSE: Holds mousewise direction, relative to player sprite
};