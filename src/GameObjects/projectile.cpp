#include "projectile.hpp"


/* Check if player is colliding with items and change movement according to that */
void Projectile::CheckCollisions(std::vector<GameObject*> objects) {
    /* hitbox rect of player */
    sf::Rect rect = GetRect();
    sf::Vector2f position = GetRectPosition();

    PhysicsVector velocity = GetVelocity();

    for (GameObject* obj : objects) {
        sf::Rect obj_rect = obj->GetRect();
        sf::Vector2f obj_pos = obj->GetPosition();

        if (obj_rect.contains(position + PhysicsVector(0,0) + velocity)) {
            if (obj_pos.x + obj_rect.width <= position.x) {
                if (obj->IsShootable()) {
                    obj->TakeDamage(GetDamage());
                }
                else {
                    SetXVelocity(0);
                }

            }
            if (obj_pos.y + obj_rect.height <= position.y) {
                if (obj->IsShootable()) {
                    obj->TakeDamage(GetDamage());
                }
                else {
                    SetYVelocity(0);
                }
            }
        }
        if (obj_rect.contains(position + PhysicsVector(rect.width,0) + velocity)) {
            if (obj_pos.x >= position.x + rect.width) {
                if (obj->IsShootable()) {
                    obj->TakeDamage(GetDamage());
                }
                else {
                    SetXVelocity(0);
                }
            }
            if (obj_pos.y + obj_rect.height <= position.y) {
                if (obj->IsShootable()) {
                    obj->TakeDamage(GetDamage());
                }
                else {
                    SetYVelocity(0);
                }
            }
        }
        if (obj_rect.contains(position + PhysicsVector(0,rect.height) + velocity)) {
            if (obj_pos.x + obj_rect.width <= position.x) {
                if (obj->IsShootable()) {
                    obj->TakeDamage(GetDamage());
                }
                else {
                    SetXVelocity(0);
                }
            }
            if (obj_pos.y >= position.y + rect.height) {
                if (obj->IsShootable()) {
                    obj->TakeDamage(GetDamage());
                }
                else {
                    SetYVelocity(0);
                }
            }
        }
        if (obj_rect.contains(position + PhysicsVector(rect.width,rect.height) + velocity)) {
            if (obj_pos.x >= position.x + rect.width) {
                if (obj->IsShootable()) {
                    obj->TakeDamage(GetDamage());
                }
                else {
                    SetXVelocity(0);
                }
            }
            if (obj_pos.y >= position.y + rect.height) {
                if (obj->IsShootable()) {
                    obj->TakeDamage(GetDamage());
                }
                else {
                    SetYVelocity(0);
                }
            }
        }
    }
}