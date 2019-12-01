#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "physicsvector.hpp"


class RectHitbox : public sf::RectangleShape {
public:
    RectHitbox() = default;
    RectHitbox(double width, double height) : sf::RectangleShape(PhysicsVector(width, height)) {} 
    ~RectHitbox() = default;

private:
};