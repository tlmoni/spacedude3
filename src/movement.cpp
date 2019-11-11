#include "movement.hpp"


Movement::Movement(double max_speed, double acceleration) : max_speed_(max_speed), acceleration_(acceleration) {
    current_velocity_ = PhysicsVector(0.0f, 0.0f);

}

/* Accelerates current_movement_ vector which represents the speed of the object. */
void Movement::Accelerate(int direction) {
    PhysicsVector acc = PhysicsVector(0.0f, 0.0f);

    switch (direction) {
        case NORTH:
            acc = acc.IncreaseBy(PhysicsVector(0.0f, -acceleration_));
            break;
        case EAST:
            acc = acc.IncreaseBy(PhysicsVector(acceleration_, 0.0f));
            break;
        case SOUTH:
            acc = acc.IncreaseBy(PhysicsVector(0.0f, acceleration_));
            break;
        case WEST:
            acc = acc.IncreaseBy(PhysicsVector(-acceleration_, 0.0f));
            break;
        case NORTH_EAST:
            acc = acc.IncreaseBy(PhysicsVector(acceleration_ / sqrt(2), -acceleration_ / sqrt(2)));
            break;
        case SOUTH_EAST:
            acc = acc.IncreaseBy(PhysicsVector(acceleration_ / sqrt(2), acceleration_ / sqrt(2)));
            break;
        case SOUTH_WEST:
            acc = acc.IncreaseBy(PhysicsVector(-acceleration_ / sqrt(2), acceleration_ / sqrt(2)));
            break;
        case NORTH_WEST:
            acc = acc.IncreaseBy(PhysicsVector(-acceleration_ / sqrt(2), -acceleration_ / sqrt(2)));
            break;
    }
    
    if (current_velocity_.Length() == 0) {
        current_velocity_ = current_velocity_.IncreaseBy(acc);
    }
    else {
        PhysicsVector unit = current_velocity_.UnitVector();
        double length_acc1 = acc.Length()*cos(acc.Angle(current_velocity_));
        PhysicsVector acc1 = PhysicsVector(unit.x*length_acc1, unit.y*length_acc1);
        PhysicsVector acc2 = acc.DecreaseBy(acc1);

        if(current_velocity_.Length() + acc1.Length() >= max_speed_) {
            PhysicsVector max_speed = PhysicsVector(unit.x*max_speed_, unit.y*max_speed_);
            acc1 = acc1.DecreaseBy(max_speed.DecreaseBy(current_velocity_));
        }
        
        current_velocity_ = current_velocity_.IncreaseBy(acc1);
        current_velocity_ = current_velocity_.IncreaseBy(acc2);
    }
    
}

void Movement::Decelerate() {
    PhysicsVector unit = current_velocity_.UnitVector();
    PhysicsVector dec = PhysicsVector(unit.x*friction, unit.y*friction);
    
    if(current_velocity_.Length() - dec.Length() < 0) {
        dec = current_velocity_;
    }

    current_velocity_ = current_velocity_.DecreaseBy(dec);
}


/* length of double type vector */
double LengthOfVector(sf::Vector2f vector) { 
    return sqrt(pow(vector.x, 2.0) + pow(vector.y, 2.0));
}

int DirectionOfVector(sf::Vector2f dir_vector) {

    if (dir_vector.x > 0 && dir_vector.y < 0) {
        return NORTH_EAST;
    }
    else if (dir_vector.x > 0 && dir_vector.y > 0) {
        return SOUTH_EAST;
    }
    else if (dir_vector.x < 0 && dir_vector.y > 0) {
        return SOUTH_WEST;
    }
    else if (dir_vector.x < 0 && dir_vector.y < 0) {
        return NORTH_WEST;
    }
    else if (dir_vector.y < 0) {
        return NORTH;
    }
    else if (dir_vector.x > 0) {
        return EAST;
    }
    else if (dir_vector.y > 0) {
        return SOUTH;
    }
    else if (dir_vector.x < 0) {
        return WEST;
    }

    return -1;
}