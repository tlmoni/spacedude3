#pragma once

#include <iostream>
#include <string>
#include "gameobject.hpp"

class GameObject;

/* Destructable wall block, subclass of GameObject */
class DestructableWall : public GameObject {
public:
    /* Constructor */
    DestructableWall(PhysicsVector pos) : GameObject(pos, "src/Textures/crate.png", RectHitbox(64.f, 64.f), DESTRUCTABLE_WALL) {
        dead_ = false;
        shootable_ = true;
        if (!break_buffer.loadFromFile("src/Audio/Sound/sound_break.ogg")) {
            std::cout << "ERROR while loading wall breaking sound" << std::endl;
        }
        break_sound.setBuffer(break_buffer);
    }

    /* Destructor */
    ~DestructableWall() = default;

    void DeathSound() {
        break_sound.play();
    }

private:
    sf::Sound break_sound;
    sf::SoundBuffer break_buffer;
};