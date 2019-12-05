#include "gameobject.hpp"

/* Constructor */
GameObject::GameObject(sf::Vector2f pos, std::string file, RectHitbox hitbox, std::string name) {
    pos_ = pos;
    name_ = name;
    texture_ = new sf::Texture();
    sprite_ = new sf::Sprite();
    if(!texture_->loadFromFile(file)){
        // Error checking.
    }
    sprite_->setTexture(*texture_);
    hitbox_ = hitbox;
    hitbox_.setFillColor(sf::Color(255,0,0,50));

    SetPosition(pos);
}

/* Destructor */
GameObject::~GameObject() {
    delete texture_;
    delete sprite_;
}

/* Sets position of the object and its sprite */
void GameObject::SetPosition(sf::Vector2f new_pos) {
    pos_ = new_pos;
    sprite_->setPosition(new_pos);
    hitbox_.setPosition(new_pos);
}

/* Set object origin */
void GameObject::SetOrigin(float x, float y) {
    sprite_->setOrigin(x,y);
    hitbox_.setOrigin(x,y);
}

/* Set object rotation */
void GameObject::SetRotation(float x, float y) {
    sprite_->setRotation(std::atan2(y, x) * 180 / M_PI); // Set the rotaion in degrees
}

/* Set new hitbox for GameObject */
void GameObject::SetHitbox(RectHitbox hitbox) {
    hitbox_ = hitbox;
}

/* Overload << operator for printing */
std::ostream& operator<<(std::ostream& os, GameObject obj) {
    os << "<" << obj.GetName() << ">";
    return os;
}
