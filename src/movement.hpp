#pragma once

#include <iostream>
#include "recthitbox.hpp"

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

extern float g_friction;

/* Class for handling all movement of GameObjects */
class Movement {
public:
    /* Constructor */
    Movement(float max_speed = 0.5f, float acceleration = 0.02f);

    /* Accelerates current_movement_ vector which represents the speed of the object. */
    void Accelerate(int direction);

    /* Slows down player movement. */
    void Decelerate(float friction);

    /* Set functions to allow changing velocity and it's attributes. */
    void SetVelocity(PhysicsVector velocity) { current_velocity_ = velocity; }
    void SetVelocity(float x, float y) { current_velocity_ = PhysicsVector(x, y); }
    void SetXVelocity(float x) { current_velocity_.x = x; }
    void SetYVelocity(float y) { current_velocity_.y = y; }
    PhysicsVector GetVelocity() { return current_velocity_; }

private:
    float max_speed_;
    float acceleration_;
    PhysicsVector current_velocity_;
};

/* Non member functions */

/* Returns the direction of the vector as an int (enum) */
int DirectionOfVector(sf::Vector2f dir_vector);
