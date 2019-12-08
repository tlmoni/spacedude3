#pragma once

#include "gameobject.hpp"

class Zombie : public GameObject {
public:
    /* Constructor */
    Zombie(PhysicsVector pos) :
    GameObject(pos, "src/Textures/zombie.png", RectHitbox(70.f, 70.f), "Zombie", 5.0f, 0.5f, 150, true) { }

    /* Destructor */
    ~Zombie() = default;

    void Action(PhysicsVector pos, std::vector<GameObject*> objects);

private:
};