#include "gameobject.hpp"

/* Constructor */
GameObject::GameObject(sf::Vector2f pos, std::string file, RectHitbox hitbox, std::string name, double max_speed, double acceleration, int hitpoints, bool shootable) :
Movement(max_speed, acceleration),
hitpoints_(hitpoints), shootable_(shootable) {
    pos_ = pos;
    name_ = name;
    texture_ = new sf::Texture();
    if(!texture_->loadFromFile(file)){
        // Error checking.
    }
    sprite_.setTexture(*texture_);
    hitbox_ = hitbox;
    hitbox_.setFillColor(sf::Color(255,0,0,50));

    SetPosition(pos);
}

/* Copy constructor */
GameObject::GameObject(const GameObject& obj) : Movement() {
    *this = obj;
}

/* Copy assignment operator */
GameObject& GameObject::operator=(const GameObject& obj) {
    name_ = obj.name_;
    pos_ = obj.pos_;
    sprite_ = obj.sprite_;
    texture_ = obj.texture_;
    hitbox_ = obj.hitbox_;
    hitpoints_ = obj.hitpoints_;
    shootable_ = obj.shootable_;

    return *this;
}

/* Destructor */
GameObject::~GameObject() {
    delete texture_;
}

/* Sets position of the object and its sprite */
void GameObject::SetPosition(sf::Vector2f new_pos) {
    pos_ = new_pos;
    sprite_.setPosition(new_pos);
    hitbox_.setPosition(new_pos);
}

/* Set object origin */
void GameObject::SetOrigin(float x, float y) {
    sprite_.setOrigin(x,y);
    hitbox_.setOrigin(x,y);
}

/* Set object rotation */
void GameObject::SetRotation(float x, float y) {
    sprite_.setRotation(std::atan2(y, x) * 180 / M_PI); // Set the rotaion in degrees
}

/* Set new hitbox for GameObject */
void GameObject::SetHitbox(RectHitbox hitbox) {
    hitbox_ = hitbox;
}

/* Check if player is colliding with items and change movement according to that */
void GameObject::CheckCollisions(std::vector<GameObject*> objects) {
    /* hitbox rect of player */
    sf::Rect rect = GetRect();
    sf::Vector2f position = GetRectPosition();

    PhysicsVector velocity = GetVelocity();

    for (GameObject* obj : objects) {
        sf::Rect obj_rect = obj->GetRect();
        sf::Vector2f obj_pos = obj->GetPosition();

        if (obj_rect.contains(position + PhysicsVector(0,0) + velocity)) {
            if (obj_pos.x + obj_rect.width <= position.x) {
                if (obj->shootable_) {
                    obj->hitpoints_ -= 10;
                }
                else {
                    SetXVelocity(0);
                }

            }
            if (obj_pos.y + obj_rect.height <= position.y) {
                if (obj->shootable_) {
                    obj->hitpoints_ -= 10;
                }
                else {
                    SetYVelocity(0);
                }
            }
        }
        if (obj_rect.contains(position + PhysicsVector(rect.width,0) + velocity)) {
            if (obj_pos.x >= position.x + rect.width) {
                if (obj->shootable_) {
                    obj->hitpoints_ -= 10;
                }
                else {
                    SetXVelocity(0);
                }
            }
            if (obj_pos.y + obj_rect.height <= position.y) {
                if (obj->shootable_) {
                    obj->hitpoints_ -= 10;
                }
                else {
                    SetYVelocity(0);
                }
            }
        }
        if (obj_rect.contains(position + PhysicsVector(0,rect.height) + velocity)) {
            if (obj_pos.x + obj_rect.width <= position.x) {
                if (obj->shootable_) {
                    obj->hitpoints_ -= 10;
                }
                else {
                    SetXVelocity(0);
                }
            }
            if (obj_pos.y >= position.y + rect.height) {
                if (obj->shootable_) {
                    obj->hitpoints_ -= 10;
                }
                else {
                    SetYVelocity(0);
                }
            }
        }
        if (obj_rect.contains(position + PhysicsVector(rect.width,rect.height) + velocity)) {
            if (obj_pos.x >= position.x + rect.width) {
                if (obj->shootable_) {
                    obj->hitpoints_ -= 10;
                }
                else {
                    SetXVelocity(0);
                }
            }
            if (obj_pos.y >= position.y + rect.height) {
                if (obj->shootable_) {
                    obj->hitpoints_ -= 10;
                }
                else {
                    SetYVelocity(0);
                }
            }
        }
    }
}

/* Overload << operator for printing */
std::ostream& operator<<(std::ostream& os, GameObject obj) {
    os << "<" << obj.GetName() << ">";
    return os;
}
