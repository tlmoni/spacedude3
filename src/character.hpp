#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Character {
public:

    Character(double max_speed, double acceleration);

private:
    double max_speed_;
    double acceleration_;
};
