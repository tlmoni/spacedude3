#pragma once

#include <iostream>
#include "gameobject.hpp"

/* Wall block, subclass of GameObject */
class Wall : public GameObject {

public:
    /* Constructor */
    Wall(PhysicsVector pos) : GameObject(pos, "src/Textures/wall.png", RectHitbox(128.f, 128.f), "Wall") { }
private:
    std::string texture = "src/Textures/wall.png";
    std::string name = "Wall";
    RectHitbox hitbox = RectHitbox(128.f, 128.f);

};