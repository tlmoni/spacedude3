#pragma once

#include <iostream>
#include <SFML/System.hpp>
#include "gameobject.hpp"
#include "../movement.hpp"
#include "../physicsvector.hpp"

/* Abstract parent class for all projectile */
class Projectile : public GameObject, public Movement {
public:
    /* Constructor */
    Projectile(PhysicsVector pos) : GameObject(pos, "src/Textures/bullet.png", RectHitbox(10.f, 10.f), "Bullet"), Movement(5, 1) { }

    double GetSlowRate() { return slow_rate_; }
    double GetSpeed() { return speed_; }
    //sf::Time GetTimer() { return bullet_timer_.getElapsedTime; }

private:
    double slow_rate_ = 0.2f;
    double speed_ = 15.f;
};