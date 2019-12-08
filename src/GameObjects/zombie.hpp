#pragma once

#include "gameobject.hpp"

class Zombie : public GameObject {
public:
    /* Constructor */
    Zombie(PhysicsVector pos) :
    GameObject(pos, "src/Textures/zombie.png", RectHitbox(64.f, 64.f), ENEMY, "Zombie", 2.0f, 0.5f, 1000, true) {
         if (!zombiedeathbuffer_.loadFromFile("src/Audio/Sound/sound_zombiedeath.ogg")) {
        std::cout << "ERROR: Loading zombie death sound 1 failed!" << std::endl;
        }
        zombiedeath_.setBuffer(zombiedeathbuffer_);

        if (!zombiedeathbuffer2_.loadFromFile("src/Audio/Sound/sound_zombiedeath2.ogg")) {
            std::cout << "ERROR: Loading zombie death sound 2 failed!" << std::endl;
        }
        zombiedeath2_.setBuffer(zombiedeathbuffer2_);

        if (!zombiedeathbuffer3_.loadFromFile("src/Audio/Sound/sound_zombiedeath3.ogg")) {
            std::cout << "ERROR: Loading zombie death sound 3 failed!" << std::endl;
        }
        zombiedeath3_.setBuffer(zombiedeathbuffer3_);
        SetOrigin(25, 30);
        }

    /* Destructor */
    ~Zombie() = default;

    void Action(PhysicsVector pos, std::vector<GameObject*> objects);

    /* Function to randomize and play death sound */
    void DeathSound();


private:
    sf::SoundBuffer zombiedeathbuffer_; // Buffer for zombie death sound effect
    sf::Sound zombiedeath_; // Zombie death sound effect
    sf::SoundBuffer zombiedeathbuffer2_; // Buffer for zombie death sound effect
    sf::Sound zombiedeath2_; // Zombie death sound effect
    sf::SoundBuffer zombiedeathbuffer3_; // Buffer for zombie death sound effect
    sf::Sound zombiedeath3_; // Zombie death sound effect
};
