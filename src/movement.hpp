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
    /* Constructor */
    Movement(double max_speed = 0.5f, double acceleration = 0.02f);

    /* Accelerates current_movement_ vector which represents the speed of the object. */
    void Accelerate(int direction);

    /* Slows down player movement */
    void Decelerate();

    void SetVelocity(PhysicsVector velocity) { current_velocity_ = velocity; }
    void SetXVelocity(double x) { current_velocity_.x = x; }
    void SetYVelocity(double y) { current_velocity_.y = y; }
    PhysicsVector GetVelocity() { return current_velocity_; }

private:
    double max_speed_;
    double acceleration_;
    PhysicsVector current_velocity_;
};

/* Non member functions */

/* Returns the length of a double type vector */
double LengthOfVector(sf::Vector2f vector);

/* Returns the direction of the vector as an int (enum) */
int DirectionOfVector(sf::Vector2f dir_vector);

