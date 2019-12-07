#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "physicsvector.hpp"

/* Class for creating hitboxes for GameObjects */
class RectHitbox : public sf::RectangleShape {
public:
    /* Default contstructor */
    RectHitbox() = default;
    /* Constructor */
    RectHitbox(float width, float height) : sf::RectangleShape(PhysicsVector(width, height)) {}
    /* Destructor */
    ~RectHitbox() = default;

private:
};
