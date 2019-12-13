#pragma once

#include "projectile.hpp"

class Zombie : public GameObject {
public:
    /* Constructor */
    Zombie(PhysicsVector pos);

    /* Destructor */
    ~Zombie() = default;

    /* Handle zombie shooting */
    std::vector<Projectile*> Action(std::vector<GameObject*> objects, PhysicsVector pos, std::string game_mode);

    /* Play a random death sound for zombie from 3 different audios. */
    void DeathSound();

    void SetWeapon(Bullet bullet) { bullet_ = bullet; }
    void SetAttackRange(float range) { attack_range_ = range; }

private:
    sf::SoundBuffer zombiedeathbuffer_; // Buffer for zombie death sound effect
    sf::Sound zombiedeath_; // Zombie death sound effect
    sf::SoundBuffer zombiedeathbuffer2_; // Buffer for zombie death sound effect
    sf::Sound zombiedeath2_; // Zombie death sound effect
    sf::SoundBuffer zombiedeathbuffer3_; // Buffer for zombie death sound effect
    sf::Sound zombiedeath3_; // Zombie death sound effect
    Bullet bullet_;
    float attack_range_;
};
