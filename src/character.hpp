#pragma once

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "recthitbox.hpp"

/* Abstract class for player characters to inherit
   Contains only virtual funtions and default constructor/destructor
   Should no be used to store any values, that is done by the respective unique characters class */
class Character {
public:
    /* Constructor */
    Character(std::string texture_file, std::string name, int hitpoints, double max_speed, double acceleration, RectHitbox hitbox) {
        texture_file_ = texture_file;
        name_ = name;
        hitpoints_ = hitpoints;
        max_speed_ = max_speed;
        acceleration_ = acceleration;
        hitbox_ = hitbox;
    }

    /* Default destructor */
    ~Character() = default;

// Get functions
    std::string GetTextureFile() { return texture_file_; }
    std::string GetIdentity() { return name_; }
    int GetHP() { return hitpoints_; }
    double GetMaxSpeed() { return max_speed_; }
    double GetAcceleration() { return acceleration_; }
    RectHitbox GetHitBox() { return hitbox_; }


private:
    std::string texture_file_;
    std::string name_;
    int hitpoints_;
    double max_speed_;
    double acceleration_;
    RectHitbox hitbox_;

};
