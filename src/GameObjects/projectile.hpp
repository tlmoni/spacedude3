#pragma once

#include <iostream>
#include "gameobject.hpp"

/* Abstract parent class for all projectile */
class Projectile : public GameObject {
public:
    /* Constructor */
    Projectile(PhysicsVector pos) : GameObject(pos, "src/Textures/bullet.png", RectHitbox(20.f, 20.f), "Bullet", 5, 1) { }

    /* Destructor */
    ~Projectile() = default;

    double GetSlowRate() { return slow_rate_; }
    double GetSpeed() { return speed_; }

private:
    double slow_rate_ = 0.6f;
    double speed_ = 30.f;
};