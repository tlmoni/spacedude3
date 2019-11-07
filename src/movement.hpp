#include <iostream>
#include <SFML/System.hpp>

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

class Movement {
public:

    Movement(double max_speed, double acceleration);

    void Move(sf::Vector2f pos_dif);

    Direction GetDirection();

private:
    double max_speed_;
    double acceleration_;
    sf::Vector2f current_movement_;
};

