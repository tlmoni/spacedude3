#include "physicsvector.hpp"

/* Returns a unit vector of the vector */
PhysicsVector PhysicsVector::UnitVector() {
    if (Length() == 0) {
        return PhysicsVector(0, 0);
    }
    return PhysicsVector(x / Length(), y / Length());
}

/* Returns the length of the vector */
float PhysicsVector::Length() {
    return sqrt(pow(x, 2) + pow(y, 2));
}

/* Calculates angle from x-axis in range -180 to 180 degrees */
float PhysicsVector::Angle() {
    return 180/M_PI*atan2(y,x);
}

/* Calculates angle from x-axis in range -180 to 180 degrees */
float PhysicsVector::AngleRad() {
    return atan2(y,x);
}

/* Returns the angle between 2 vectors (self & parameter) */
float PhysicsVector::AngleBetween(PhysicsVector vector) {
    float length = this->Length() * vector.Length();
    float angle = acosf(this->DotProduct(vector) / length);
    if (isnanf(angle)) {
        return 0.f;
    }
    return angle;
}

/* Rotate vector by angle(degrees) */
void PhysicsVector::Rotate(float angle) {
    float length = Length();
    angle = angle*M_PI/180;
    x = length * cosf(AngleRad() + angle);
    y = length * sinf(AngleRad() + angle);
}

/* Returns the result of the vector multiplication (self & parameter) */
float PhysicsVector::DotProduct(PhysicsVector vector) {
    return this->x*vector.x + this->y*vector.y;
}

/* Multiply vector by some value */
PhysicsVector PhysicsVector::Scale(float multiplier) {
    return PhysicsVector(this->x * multiplier, this->y * multiplier);
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
