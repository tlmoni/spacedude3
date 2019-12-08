#include "zombie.hpp"


void Zombie::Action(PhysicsVector pos, std::vector<GameObject*> objects) {
    PhysicsVector direction = pos - GetPosition();

    Move(direction);
    CheckCollisions(objects);
    SetPosition(GetPosition() + GetVelocity());
    SetRotation(direction);
}

void Zombie::DeathSound() {
    int random_integer = rand() % 3;
    if (random_integer == 0) {
        zombiedeath_.play();
    }
    else if (random_integer == 1) {
        zombiedeath2_.play();
    }
    else {
        zombiedeath3_.play();
    }
    std::cout << random_integer << std::endl;
}
