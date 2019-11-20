#pragma once

#include <iostream>
#include <SFML/System.hpp>
#include <cmath>
#include "physicsvector.hpp"

enum Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST,
    NORTH_EAST,
    SOUTH_EAST,
    SOUTH_WEST,
    NORTH_WEST
};

extern double g_friction;

class Movement {
public:

    Movement(double max_speed = 0.5f, double acceleration = 0.02f);

    /* Accelerates current_movement_ vector which represents the speed of the object. */
    void Accelerate(int direction);
    void Decelerate();

    PhysicsVector GetVelocity() { return current_velocity_; }

private:
    double max_speed_;
    double acceleration_;
    double turn_speed_;

    PhysicsVector current_velocity_; // Speed of the object
};

/* Non member functions */

/* length of double type vector */
double LengthOfVector(sf::Vector2f vector);

/* Returns the direction vector is pointing at */
int DirectionOfVector(sf::Vector2f dir_vector);

