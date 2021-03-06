#pragma once

#include <iostream>
#include "gameobject.hpp"

struct Bullet {
    std::string texture;
    RectHitbox hitbox;
    int type;
    float max_speed;
    float acceleration;
    float damage;
    PhysicsVector origin;
};

const static Bullet plasma = {"src/Textures/bullet.png", RectHitbox(20.f, 20.f), BULLET, 30.f, 0.4f, 15, PhysicsVector(10, 10)};
const static Bullet rock = {"src/Textures/rock.png", RectHitbox(17.f, 17.f), BULLET, 30.f, 1.5f, 10, PhysicsVector(9, 9)};
const static Bullet pellet = {"src/Textures/pellet.png", RectHitbox(20.f, 20.f), BULLET, 30.f, 1.7f, 80, PhysicsVector(10, 10)};
const static Bullet heal = {"src/Textures/heal.png", RectHitbox(20.f, 20.f), BULLET, 0.0f, 0.01f, 0, PhysicsVector(10, 10)};
const static Bullet skull = {"src/Textures/skull.png", RectHitbox(33.f, 33.f), BULLET, 15.f, 0.1f, 50, PhysicsVector(17, 17)};

/* Abstract parent class for all projectile */
class Projectile : public GameObject {
public:
    /* Constructor */
    Projectile(PhysicsVector pos, int owner, Bullet bullet = plasma) :
    GameObject(pos, bullet.texture, bullet.hitbox, bullet.type, bullet.max_speed, bullet.acceleration, bullet.damage),
    owner_(owner) { SetOrigin(bullet.origin.x, bullet.origin.y); }

    /* Destructor */
    ~Projectile() = default;

    /* Check if player is colliding with items and change movement according to that */
    bool CheckCollisions(std::vector<GameObject*> objects);

    int GetOwner() { return owner_; }

private:
    int owner_;
};
