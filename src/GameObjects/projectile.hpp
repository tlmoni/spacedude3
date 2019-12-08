#pragma once

#include <iostream>
#include "gameobject.hpp"

/* Abstract parent class for all projectile */
class Projectile : public GameObject {
public:
    /* Constructor */
    Projectile(PhysicsVector pos) : GameObject(pos, "src/Textures/bullet.png", RectHitbox(10.f, 10.f), "Bullet", 5, 1, 0, false, 10) { }

    /* Destructor */
    ~Projectile() = default;

    void CheckCollisions(std::vector<GameObject*> objects);

    double GetSlowRate() { return slow_rate_; }
    double GetSpeed() { return speed_; }

private:
    double slow_rate_ = 0.6f;
    double speed_ = 30.f;
};
