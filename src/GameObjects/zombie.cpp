#include "zombie.hpp"


void Zombie::Action(PhysicsVector pos, std::vector<GameObject*> objects) {
    PhysicsVector direction = pos - GetPosition();

    Move(direction);
    CheckCollisions(objects);
    SetPosition(GetPosition() + GetVelocity());
    SetRotation(direction);
}
