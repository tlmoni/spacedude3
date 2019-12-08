#include "zombie.hpp"

Zombie::Zombie(PhysicsVector pos) : GameObject(pos, "src/Textures/zombie.png", RectHitbox(64.f, 64.f), ENEMY, 5.0f, 0.05f, 10, 500, true, 1000) {
    bullet_ = rock;
    SetOrigin(25, 30);
}

std::vector<Projectile*> Zombie::Action(std::vector<GameObject*> objects, PhysicsVector pos) {
    PhysicsVector direction = pos - GetPosition();
    std::vector<Projectile*> projectiles;

    sf::Time time = attack_timer_.getElapsedTime();
    if (direction.Length() < 300 && time.asMilliseconds() > GetAttackDelay()) {
        direction = direction.UnitVector();
        attack_timer_.restart();
        /*
        if (sound_on) {
            gunshot_.play();
        }
        */

        Projectile* bullet = new Projectile(GetPosition(), ENEMY, bullet_);
        PhysicsVector vel = GetVelocity().UnitVector();
        SetVelocity(vel.Scale(0.01f));
        direction = PhysicsVector(direction.x * bullet->GetMaxSpeed()/sqrt(2), direction.y * bullet->GetMaxSpeed()/sqrt(2));
        bullet->SetVelocity(direction);
        projectiles.push_back(bullet);
    }

    Move(direction);
    CheckCollisions(objects);
    SetPosition(GetPosition() + GetVelocity());
    SetRotation(direction);

    return projectiles;
}