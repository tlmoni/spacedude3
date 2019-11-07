#include "gameobject.hpp"

GameObject::GameObject(sf::Vector2f pos, std::string file) : pos_(pos) {
    if(!texture_.loadFromFile(file)){
        //Error checking
    }
    sprite_.setTexture(texture_);

}

void GameObject::SetPosition(sf::Vector2f new_pos) {
    pos_ = new_pos;
    sprite_.setPosition(new_pos);

}

void GameObject::SetOrigin(float x, float y){
    sprite_.setOrigin(x,y);
}