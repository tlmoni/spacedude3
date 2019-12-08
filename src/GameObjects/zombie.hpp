#pragma once

#include "gameobject.hpp"

class Zombie : public GameObject {
public:
    /* Constructor */
    Zombie(PhysicsVector pos) :
    GameObject(pos, "src/Textures/zombie.png", RectHitbox(64.f, 64.f), ENEMY, "Zombie", 2.0f, 0.5f, 1000, true) { SetOrigin(25, 30); }

    /* Destructor */
    ~Zombie() = default;

    void Action(PhysicsVector pos, std::vector<GameObject*> objects);

private:
};