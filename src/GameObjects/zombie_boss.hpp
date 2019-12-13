#pragma once

#include "zombie.hpp"

class ZombieBoss : public Zombie {
public:
    /* Constructor */
    ZombieBoss(PhysicsVector pos) : Zombie(pos) {
        SetMaxHitPoints(1000.f);
        SetAttackDelay(3000);
        SetMaxSpeed(2);

    }

    /* Destructor */
    ~ZombieBoss() = default;


private:
};
