#include "zombie.hpp"


void Zombie::Action(GameObject* obj, std::vector<GameObject*> objects) {
    PhysicsVector direction = GetPosition() - obj->GetPosition();
    PhysicsVector dir_unit = direction.UnitVector();

    Move(direction);
    CheckCollisions(objects);
    SetPosition(GetPosition() + GetVelocity());
}