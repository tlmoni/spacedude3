#pragma once

#include "character.hpp"

/* Unique character "template"
   Makes use of functions held within Character class.
   Also used to store all unique attributes of a character */
class CharacterSpurdo : public Character {
public:
    CharacterSpurdo() : Character("src/Textures/spacedude.png", "Spacedude", 150, 5.0f, 1.0f, RectHitbox(50.f, 50.f), PhysicsVector(26,32)) { }

private:
};
