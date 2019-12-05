#pragma once

#include "gameobject.hpp"

/* Wall block, subclass of GameObject */
class Wall : public GameObject {
public:
    /* Constructor */
    Wall(sf::Vector2f pos, std::string file, RectHitbox hitbox) : GameObject(pos, file, hitbox, "Wall") { }
private:

};