#pragma once

#include "gameobject.hpp"


//Basic wall block
class Wall : public GameObject {
public:
    Wall(sf::Vector2f pos, std::string file, RectHitbox hitbox) : GameObject(pos, file, hitbox, "Wall") {}

private:

};