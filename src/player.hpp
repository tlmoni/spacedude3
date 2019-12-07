#pragma once

#include <iostream>
#include "character_spacedude.hpp"
#include "GameObjects/projectile.hpp"

/* Forward declaration of Scene needed here */
class Projectile;

/* Allows the usege of global variable main_window and its functions */
extern sf::RenderWindow* main_window;

/* Player object, subclass of GameObject,  */
class Player : public GameObject {
public:
    /* Constructor takes in Vector2f template class for manipulating 2-dimensional vectors (Position on the grid) */
    Player(Character* character, sf::Vector2f pos);

    /* Default destructor */
    ~Player() = default;

    /* Function to handle player movement and events and update them to the scene */
    void Loop();

    /* Function handling keypress and their effects on player character */
    std::vector<Projectile*> Action(std::vector<GameObject*> objects);

    /* Function resposible for updating player character position */
    void Move(PhysicsVector dir_vector);

    /* Rotote player */
    void Rotate();

    /* Function that calculates current mousewise direction, relative to player sprite */
    PhysicsVector GetCurrentCursorDirection();

    sf::View GetView() { return player_cam_; }

private:
    sf::View player_cam_;
    sf::Vector2f direction_cursor_; // MOUSE: Holds mousewise direction, relative to player sprite
    sf::Clock reload_timer_;
};
