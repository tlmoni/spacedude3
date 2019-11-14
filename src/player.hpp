#pragma once

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "character.hpp"
#include "scene.hpp"
#include "GameObjects/gameobject.hpp"
#include "movement.hpp"

/* Allows the usege of global variable main_window and its functions */
extern sf::RenderWindow* main_window;
extern GameObject* map;


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
    bool Move(sf::Vector2f dir_vector);

    void Rotate();

    /* Function that calculates current mousewise direction, relative to player sprite */
    sf::Vector2f GetCurrentCursorDirection();
    sf::View GetView() { return player_cam_; } // Return player camera position.

private:
    Movement movement_;
    sf::View player_cam_;
    sf::Vector2f direction_cursor_; // MOUSE: Holds mousewise direction, relative to player sprite
    // Character character_;
};