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

    /* Constructor from sf::Vector2f */
    PhysicsVector(sf::Vector2f vector) : sf::Vector2f(vector) { }

    /* Returns a unit vector of the vector */
    PhysicsVector UnitVector();

    /* Returns the length of the vector */
    double Length();

    /* Calculates angle from x-axis in range -180 to 180 degrees */
    double Angle();

    /* Returns the angle between 2 vectors (self & parameter), returns angle in radians. */
    double AngleBetween(PhysicsVector vector);

    /* Dot product of 2 vectors, returns double */
    double MultiplyWith(PhysicsVector vector);

    /* Multiply vector by some value */
    PhysicsVector MultiplyBy(double multiplier);

    /* Returns the sum of the vectors (self & parameter) */
    PhysicsVector IncreaseBy(PhysicsVector vector);

    /* Returns the subtraction of the vectors (self & parameter) */
    PhysicsVector DecreaseBy(PhysicsVector vector);
};

/* Overload << operator for printing physicsvectors */
std::ostream& operator<<(std::ostream& os, PhysicsVector vector);