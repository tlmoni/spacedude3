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
    Character(std::string texture_file, RectHitbox hitbox, std::string name, double max_speed, double acceleration, float damage, float hitpoints, int attack_delay, PhysicsVector origin) {
        texture_file_ = texture_file;
        name_ = name;
        damage_ = damage;
        hitpoints = hitpoints;
        max_speed_ = max_speed;
        acceleration_ = acceleration;
        hitbox_ = hitbox;
        origin_ = origin;
        attack_delay_ = attack_delay;
    }

    /* Default destructor */
    ~Character() = default;

    // Get functions
    std::string GetTextureFile() { return texture_file_; }
    std::string GetIdentity() { return name_; }
    float GetDamage() { return damage_; }
    float GetHP() { return hitpoints_; }
    double GetMaxSpeed() { return max_speed_; }
    double GetAcceleration() { return acceleration_; }
    RectHitbox GetHitBox() { return hitbox_; }
    PhysicsVector GetOrigin() { return origin_; }
    int GetAttackDelay() { return attack_delay_; }

private:
    std::string texture_file_;
    std::string name_;
    float hitpoints_;
    double max_speed_;
    double acceleration_;
    RectHitbox hitbox_;
    PhysicsVector origin_;
    float damage_;
    int attack_delay_;
};
