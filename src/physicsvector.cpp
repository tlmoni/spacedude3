#include "physicsvector.hpp"

/* Returns a unit vector of the vector */
PhysicsVector PhysicsVector::UnitVector() {
    if (Length() == 0) {
        return PhysicsVector(0, 0);
    }
    return PhysicsVector(x / Length(), y / Length());
}

/* Returns the length of the vector */
double PhysicsVector::Length() {
    return sqrt(pow(x, 2.0) + pow(y, 2.0));
}

/* Calculates angle from x-axis in range -180 to 180 degrees */
double PhysicsVector::Angle() {
    return 180/M_PI*atan2(y,x);
}

/* Returns the angle between 2 vectors (self & parameter) */
double PhysicsVector::AngleBetween(PhysicsVector vector) {
    double length = this->Length() * vector.Length();
    double angle = acosf(this->MultiplyWith(vector) / length);

    return angle;
}

/* Returns the result of the vector multiplication (self & parameter) */
double PhysicsVector::MultiplyWith(PhysicsVector vector) {
    return this->x*vector.x + this->y*vector.y;
}

/* Returns the sum of the vectors (self & parameter) */
PhysicsVector PhysicsVector::IncreaseBy(PhysicsVector vector) {
    return PhysicsVector(this->x + vector.x, this->y + vector.y);
}

/* Returns the subtraction of the vectors (self & parameter) */
PhysicsVector PhysicsVector::DecreaseBy(PhysicsVector vector) {
    return PhysicsVector(this->x - vector.x, this->y - vector.y);
}

/* Overload << operator for printing physicsvectors */
std::ostream& operator<<(std::ostream& os, PhysicsVector vector)
{
    os << "[" << vector.x << ", " << vector.y;
    os << "]";
    return os;
}
