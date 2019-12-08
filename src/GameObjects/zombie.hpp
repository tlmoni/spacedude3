#pragma once

#include "projectile.hpp"

class Zombie : public GameObject {
public:
    /* Constructor */
    Zombie(PhysicsVector pos);

    /* Destructor */
    ~Zombie() = default;

    std::vector<Projectile*> Action(std::vector<GameObject*> objects, PhysicsVector pos);

private:
    Bullet bullet_;
};
