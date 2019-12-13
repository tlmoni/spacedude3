#pragma once

#include "zombie.hpp"

class ZombieBoss : public Zombie {
public:
    /* Constructor */
    ZombieBoss(PhysicsVector pos) : Zombie(pos) {
        SetMaxHitPoints(5000.f);
        SetAttackDelay(3000);
        SetMaxSpeed(2.7f);
        SetSprite("src/Textures/zombieboss.png");
        GetSprite().setScale(1.5f, 1.5f);
        SetWeapon(skull);
        SetAttackRange(300);

    }

    /* Destructor */
    ~ZombieBoss() = default;


private:
};
