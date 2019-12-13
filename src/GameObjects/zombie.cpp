#include "zombie.hpp"

Zombie::Zombie(PhysicsVector pos) : GameObject(pos, "src/Textures/zombie.png", RectHitbox(62.f, 62.f), ENEMY, 5.0f, 0.1f, 10, 500, true, 1000) {
    attack_range_ = 100;
    bullet_ = rock;
    SetOrigin(25, 30);
    int random_integer = rand() % 3;
    if (random_integer == 0) {
        SetSprite("src/Textures/zombie.png");
    }
    else if (random_integer == 1) {
        SetSprite("src/Textures/zombie2.png");
    }
    else {
        SetSprite("src/Textures/zombie3.png");
    }
    if (!zombiedeathbuffer_.loadFromFile("src/Audio/Sound/sound_zombiedeath.ogg")) {
        std::cout << "ERROR: Loading zombie death sound 1 failed!" << std::endl;
    }
    zombiedeath_.setBuffer(zombiedeathbuffer_);

    if (!zombiedeathbuffer2_.loadFromFile("src/Audio/Sound/sound_zombiedeath2.ogg")) {
        std::cout << "ERROR: Loading zombie death sound 2 failed!" << std::endl;
    }
    zombiedeath2_.setBuffer(zombiedeathbuffer2_);

    if (!zombiedeathbuffer3_.loadFromFile("src/Audio/Sound/sound_zombiedeath3.ogg")) {
        std::cout << "ERROR: Loading zombie death sound 3 failed!" << std::endl;
    }
    zombiedeath3_.setBuffer(zombiedeathbuffer3_);
}

/* Handle zombie shooting */
std::vector<Projectile*> Zombie::Action(std::vector<GameObject*> objects, PhysicsVector pos) {
    PhysicsVector direction = pos - GetPosition();
    std::vector<Projectile*> projectiles;

    if (direction.Length() > 500) {
        direction = PhysicsVector(0.f, 0.f);
    }
    sf::Time time = attack_timer_.getElapsedTime();
    if (direction.Length() < attack_range_ && time.asMilliseconds() > GetAttackDelay()) {
        direction = direction.UnitVector();
        attack_timer_.restart();

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

/* Play a random death sound for zombie from 3 different audios. */
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
}
