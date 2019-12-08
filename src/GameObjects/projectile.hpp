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
};

const static Bullet plasma = {"src/Textures/bullet.png", RectHitbox(10.f, 10.f), BULLET, 30.f, 0.6f, 10};
const static Bullet rock = {"src/Textures/rock.png", RectHitbox(17.f, 17.f), BULLET, 30.f, 1.0f, 10};

/* Abstract parent class for all projectile */
class Projectile : public GameObject {
public:
    /* Constructor */
    Projectile(PhysicsVector pos, int owner, Bullet bullet = plasma) :
    GameObject(pos, bullet.texture, bullet.hitbox, bullet.type, bullet.max_speed, bullet.acceleration, bullet.damage),
    owner_(owner) { }

    /* Destructor */
    ~Projectile() = default;

    void CheckCollisions(std::vector<GameObject*> objects);

    int GetOwner() { return owner_; }

private:
    int owner_;
};
