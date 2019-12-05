#pragma once

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "recthitbox.hpp"

// Abstract class for player characters to inherit
// Contains only virtual funtions and default constructor/destructor
// Should no be used to store any values, that is done by the respective unique characters class

class Character {
public:

// Constructor & destructor
    Character() = default;

    ~Character() = default;

// Get functions
    virtual std::string GetIdentity() = 0;
    virtual int GetHP() = 0;
    virtual int GetAmmo() = 0;
    virtual double GetMoveSpeed() = 0;
    virtual double GetAcceleration() = 0;
    virtual RectHitbox GetHitBox() = 0;

    virtual std::string GetTextureFile() = 0;

private:
};
