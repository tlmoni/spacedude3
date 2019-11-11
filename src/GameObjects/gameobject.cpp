#include "gameobject.hpp"

GameObject::GameObject(sf::Vector2f pos) : pos_(pos) {


}

/* Sets position of the object and it's sprite */
void GameObject::SetPosition(sf::Vector2f new_pos) {
    pos_ = new_pos;
    sprite_.setPosition(new_pos);
}