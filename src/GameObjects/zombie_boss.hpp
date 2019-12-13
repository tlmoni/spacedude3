#pragma once

#include "zombie.hpp"

class ZombieBoss : public Zombie {
public:
    /* Constructor */
    ZombieBoss(PhysicsVector pos) : Zombie(pos) {
        SetMaxHitPoints(5000.f);
        SetAttackDelay(3000);
<<<<<<< HEAD
        SetMaxSpeed(2.7f);
        SetSprite("src/Textures/zombieboss.png");
        GetSprite().setScale(1.5f, 1.5f);
=======
        SetMaxSpeed(2);
        int random_integer = rand() % 3;
        if (random_integer == 0) {
            SetSprite("src/Textures/zombieboss.png");
        }
        else if (random_integer == 1) {
            SetSprite("src/Textures/zombieboss2.png");
        }
        else {
            SetSprite("src/Textures/zombieboss3.png");
        }
        GetSprite().setScale(1.5f,1.5f);
>>>>>>> fd7c7ffa49b058a074b44291f596ab19bba6d778
        SetWeapon(skull);
        SetAttackRange(300);

    }

    /* Destructor */
    ~ZombieBoss() = default;


private:
};
