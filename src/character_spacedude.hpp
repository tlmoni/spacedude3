#pragma once

#include "character.hpp"

/* Unique character "template"
   Makes use of functions held within Character class.
   Also used to store all unique attributes of a character */
class CharacterSpurdo : public Character {
public:
    CharacterSpurdo() : Character("src/Textures/spacedudebody.png", RectHitbox(50.f, 50.f), "Spacedude", 5.0f, 1.0f, 2.f, 150, 100, PhysicsVector(26,32)) { }
private:
};
