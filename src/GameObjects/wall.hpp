#pragma once

#include "gameobject.hpp"


//Basic wall block
class Wall : public GameObject {
public:
    Wall(sf::Vector2f pos, std::string file, RectHitbox hitbox = RectHitbox(16.f, 16.f)) : GameObject(pos, file, hitbox) {}


private:

};