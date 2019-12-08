#pragma once

#include "projectile.hpp"

class Zombie : public GameObject {
public:
    /* Constructor */
    Zombie(PhysicsVector pos);

    /* Destructor */
    ~Zombie() = default;

    std::vector<Projectile*> Action(std::vector<GameObject*> objects, PhysicsVector pos);

    /* Function to randomize and play death sound */
    void DeathSound();


private:
    sf::SoundBuffer zombiedeathbuffer_; // Buffer for zombie death sound effect
    sf::Sound zombiedeath_; // Zombie death sound effect
    sf::SoundBuffer zombiedeathbuffer2_; // Buffer for zombie death sound effect
    sf::Sound zombiedeath2_; // Zombie death sound effect
    sf::SoundBuffer zombiedeathbuffer3_; // Buffer for zombie death sound effect
    sf::Sound zombiedeath3_; // Zombie death sound effect
    Bullet bullet_;
};
