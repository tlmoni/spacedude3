#include "movement.hpp"


Movement::Movement(double max_speed, double acceleration) : max_speed_(max_speed), acceleration_(acceleration) {
    current_movement_ = sf::Vector2f(0.0f, 0.0f);

}