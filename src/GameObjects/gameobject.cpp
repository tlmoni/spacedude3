
#include "gameobject.hpp"

void GameObject::SetPosition(sf::Vector2f new_pos) {
    pos_ = new_pos;
    sprite_.setPosition(new_pos);
}