#pragma once

#include <SFML/System.hpp>
#include <math.h>
#include <iostream>

class PhysicsVector : public sf::Vector2f {
public:
    PhysicsVector() = default;
    PhysicsVector(double x, double y) : sf::Vector2f(x,y) { }

    PhysicsVector UnitVector();
    double Length();
    /* Calculates angle from x-axis in range -180 to 180 degrees */
    double Angle();
    double AngleBetween(PhysicsVector vector);
    double MultiplyWith(PhysicsVector vector);
    PhysicsVector IncreaseBy(PhysicsVector vector);
    PhysicsVector DecreaseBy(PhysicsVector vector);
};

std::ostream& operator<<(std::ostream& os, PhysicsVector vector);