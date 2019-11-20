#include "physicsvector.hpp"


PhysicsVector PhysicsVector::UnitVector() {
    return PhysicsVector(x / Length(), y / Length());
}


double PhysicsVector::Length() {
    return sqrt(pow(x, 2.0) + pow(y, 2.0));
}

double PhysicsVector::Angle(PhysicsVector vector) {
    double length = this->Length() * vector.Length();
    double angle = acosf(this->MultiplyWith(vector) / length);

    return angle;
}

double PhysicsVector::MultiplyWith(PhysicsVector vector) {
    return this->x*vector.x + this->y*vector.y;
}

PhysicsVector PhysicsVector::IncreaseBy(PhysicsVector vector) {
    return PhysicsVector(this->x + vector.x, this->y + vector.y);
}

PhysicsVector PhysicsVector::DecreaseBy(PhysicsVector vector) {
    return PhysicsVector(this->x - vector.x, this->y - vector.y);
}

std::ostream& operator<<(std::ostream& os, PhysicsVector vector) 
{ 
    os << "[" << vector.x << ", " << vector.y;
    os << "]";
    return os; 
}
