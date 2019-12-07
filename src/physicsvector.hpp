#pragma once

#include <SFML/System.hpp>
#include <cmath>
#include <ctgmath>
#include <iostream>

/* Subclass of sf::Vector2f with additional features */
class PhysicsVector : public sf::Vector2f {
public:
    /* Default constructor */
    PhysicsVector() = default;

    /* Constructor */
    PhysicsVector(float x, float y) : sf::Vector2f(x,y) { }

    /* Constructor from sf::Vector2f */
    PhysicsVector(sf::Vector2f vector) : sf::Vector2f(vector) { }

    /* Returns a unit vector of the vector */
    PhysicsVector UnitVector();

    /* Returns the length of the vector */
    float Length();

    /* Calculates angle from x-axis in range -180 to 180 degrees */
    float Angle();

    /* Returns the angle between 2 vectors (self & parameter), returns angle in radians. */
    float AngleBetween(PhysicsVector vector);

    /* Dot product of 2 vectors, returns double */
    float DotProduct(PhysicsVector vector);

    /* Multiply vector by some value */
    PhysicsVector MultiplyBy(float multiplier);

    /* Returns the sum of the vectors (self & parameter) */
    PhysicsVector IncreaseBy(PhysicsVector vector);

    /* Returns the subtraction of the vectors (self & parameter) */
    PhysicsVector DecreaseBy(PhysicsVector vector);
};

/* Overload << operator for printing physicsvectors */
std::ostream& operator<<(std::ostream& os, PhysicsVector vector);
