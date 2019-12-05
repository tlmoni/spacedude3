#pragma once

#include <SFML/System.hpp>
#include <math.h>
#include <iostream>

/* Subclass of sf::Vector2f with additional features */
class PhysicsVector : public sf::Vector2f {
public:
    /* Default constructor */
    PhysicsVector() = default;

    /* Constructor */
    PhysicsVector(double x, double y) : sf::Vector2f(x,y) { }

    /* Returns a unit vector of the vector */
    PhysicsVector UnitVector();

    /* Returns the length of the vector */
    double Length();

    /* Calculates angle from x-axis in range -180 to 180 degrees */
    double Angle();
    double AngleBetween(PhysicsVector vector);
    double MultiplyWith(PhysicsVector vector);

    /* Returns the sum of the vectors (self & parameter) */
    PhysicsVector IncreaseBy(PhysicsVector vector);

    /* Returns the subtraction of the vectors (self & parameter) */
    PhysicsVector DecreaseBy(PhysicsVector vector);
};

std::ostream& operator<<(std::ostream& os, PhysicsVector vector);