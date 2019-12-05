#pragma once

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "character_spurdo.hpp"
#include "GameObjects/gameobject.hpp"
#include "GameObjects/projectile.hpp"
#include "movement.hpp"
#include "scene.hpp"


/* Forward declaration of Scene needed here */
class Scene;

/* Allows the usege of global variable main_window and its functions */
extern sf::RenderWindow* main_window;
extern Scene* scene;

/* Player object, subclass of GameObject,  */
class Player : public GameObject, public Movement {
public:
    /* Constructor takes in Vector2f template class for manipulating 2-dimensional vectors (Position on the grid) */
    Player(Character* character, sf::Vector2f pos);

    /* Default destructor */
    ~Player();

    /* Function to handle player movement and events and update them to the scene */
    void Loop();

    /* Function handling keypress and their effects on player character */
    bool Action();

    /* Function resposible for updating player character position */
    bool Move(PhysicsVector dir_vector);

    /* Rotote player */
    void Rotate();

    /* Check if player is colliding with items and change movement according to that */
    void CheckCollisions();

    /* Updates bullet positions and deceleration */
    void UpdateBullets();

    /* Function that calculates current mousewise direction, relative to player sprite */
    PhysicsVector GetCurrentCursorDirection();

    sf::View GetView() { return player_cam_; }
    std::vector<Projectile*> GetProjectiles() { return projectiles_; }

private:
    std::vector<Projectile*> projectiles_;
    sf::View player_cam_;
    sf::Vector2f direction_cursor_; // MOUSE: Holds mousewise direction, relative to player sprite
    Character* character_;
};
