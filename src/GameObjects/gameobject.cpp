#include "gameobject.hpp"

GameObject::GameObject(sf::Vector2f pos, std::string file, RectHitbox hitbox) : pos_(pos) {
    if(!texture_.loadFromFile(file)){
        // Error checking.
    }
    sprite_.setTexture(texture_);
    hitbox_ = hitbox;
    hitbox_.setFillColor(sf::Color(255,0,0,50));

    SetPosition(pos);
}

/* Sets position of the object and it's sprite */
void GameObject::SetPosition(sf::Vector2f new_pos) {
    pos_ = new_pos;
    sprite_.setPosition(new_pos);
    hitbox_.setPosition(new_pos);
}

void GameObject::SetOrigin(float x, float y) {
    sprite_.setOrigin(x,y);
}

void GameObject::SetRotation(float x, float y) {
    sprite_.setRotation(std::atan2(y, x) * 180 / M_PI); // Set the rotaion in degrees
}

void GameObject::SetHitbox(RectHitbox hitbox) {
    hitbox_ = hitbox;
}