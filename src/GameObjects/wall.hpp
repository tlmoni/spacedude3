#pragma once

#include <iostream>
#include <string>
#include "gameobject.hpp"

class GameObject;

/* Wall block, subclass of GameObject */
class Wall : public GameObject {
public:
    /* Constructor */
    Wall(PhysicsVector pos, std::string texture) : GameObject(pos, texture, RectHitbox(64.f, 64.f), WALL) { dead_ = false; }

    /* Destructor */
    ~Wall() = default;
private:
};
