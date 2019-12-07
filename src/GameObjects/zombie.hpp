#pragma once

#include "gameobject.hpp"

class Zombie : public GameObject {
public:
    Zombie(PhysicsVector pos) :
    GameObject(pos, "src/Textures/duderinosmall.png", RectHitbox(70.f, 70.f), "Zombie", 9.0f, 1.5f, 150, true) {}
private:
};