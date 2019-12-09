#pragma once

#include <iostream>
#include <SFML/Audio.hpp>
#include "character_spacedude.hpp"
#include "GameObjects/projectile.hpp"

enum WeaponType {
    BLASTER,
    SHOTGUN
};

struct Weapon {
    int type;
    Bullet bullet;
    int shoot_delay;
    std::string texture;
};

const static Weapon blaster = {BLASTER, plasma, 100, "src/Textures/blaster.png"};
const static Weapon shotgun = {SHOTGUN, pellet, 500, "src/Textures/shotgun.png"};

// Forward declaration of Scene needed here
class Projectile;

// Allows the usege of global variable main_window and its functions
extern sf::RenderWindow* main_window;

// Allows the usage of global variables sound_on and music_on
extern bool sound_on, music_on;

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

    std::vector<Projectile*> Shoot();

    void SwitchWeapon(int weapon_type);

    /* Rotote player */
    void Rotate();

    /* Function that calculates current mousewise direction, relative to player sprite */
    PhysicsVector GetCurrentCursorDirection();

    sf::View GetView() { return player_cam_; }

private:
    sf::View player_cam_;
    sf::Vector2f direction_cursor_; // MOUSE: Holds mousewise direction, relative to player sprite
    sf::SoundBuffer buffer_; // Buffer for gun sound effect
    sf::Sound gunshot_; // Gun sound effect
    Weapon weapon_;
};
