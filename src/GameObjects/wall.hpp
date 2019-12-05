#pragma once

#include <iostream>
#include "gameobject.hpp"

/* Wall block, subclass of GameObject */
class Wall : public GameObject {

public:
    /* Constructor */
    Wall(PhysicsVector pos) : GameObject(pos, "src/Textures/crate.png", RectHitbox(64.f, 64.f), "Wall") { }
private:
};
