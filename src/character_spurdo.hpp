#pragma once

#include "character.hpp"

// Unique character "template"
// Makes use of functions held within Character class.
// Also used to store all unique attributes of a character

class CharacterSpurdo : public Character {
public:
    CharacterSpurdo() : Character() {}

// Get functions
    virtual std::string GetIdentity() { return identity_; }
    virtual int GetHP() { return hitpoints_; }
    virtual int GetAmmo() { return ammo_; }
    virtual double GetMoveSpeed() { return maxmovespeed_; }
    virtual double GetAcceleration() { return acceleration_; }
    virtual RectHitbox GetHitBox() { return hitbox_; }

    virtual std::string GetTextureFile() { return texture_file_; }

private:

// Unique attributes

    std::string identity_ = "Spurdo";
    int hitpoints_ = 100;
    int ammo_ = 30;
    double maxmovespeed_ = 7.0f;
    double acceleration_ = 1.5f;
    RectHitbox hitbox_ = RectHitbox(70.f, 70.f);
    std::string texture_file_ = "src/Textures/duderinosmall.png";

};
