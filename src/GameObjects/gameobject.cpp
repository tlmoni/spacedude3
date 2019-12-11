#include "gameobject.hpp"

/* Constructor */
GameObject::GameObject(sf::Vector2f pos, std::string file, RectHitbox hitbox, int type, double max_speed,
                       double acceleration, int damage, float hitpoints, bool shootable, float attack_delay) :
Movement(max_speed, acceleration) {
    hitpoints_ = hitpoints;
    max_hitpoints_ = hitpoints;
    shootable_ = shootable;
    damage_ = damage;
    pos_ = pos;
    type_ = type;
    attack_delay_ = attack_delay;
    texture_ = new sf::Texture();
    if(!texture_->loadFromFile(file)) {
        // Error checking.
    }
    sprite_.setTexture(*texture_);

    hpbar_.setFillColor(sf::Color::Green);
    hpbar_.setSize(sf::Vector2f(64, 4));
    hpbarbackground_.setFillColor(sf::Color::Red);
    hpbarbackground_.setSize(sf::Vector2f(64, 4));

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
void GameObject::SetPosition(PhysicsVector new_pos) {
    pos_ = new_pos;
    sprite_.setPosition(new_pos);
    hitbox_.setPosition(new_pos);
    hpbar_.setPosition(new_pos + sf::Vector2f(-32, -42));
    hpbarbackground_.setPosition(new_pos + sf::Vector2f(-32, -42));
}

/* Set object origin */
void GameObject::SetOrigin(float x, float y) {
    sprite_.setOrigin(x,y);
    hitbox_.setOrigin(x,y);
}

/* Set object rotation */
void GameObject::SetRotation(PhysicsVector direction) {
    sprite_.setRotation(std::atan2(direction.y, direction.x) * 180 / M_PI); // Set the rotaion in degrees
}

/* Set new hitbox for GameObject */
void GameObject::SetHitbox(RectHitbox hitbox) {
    hitbox_ = hitbox;
}

/* Handle hpbar updating with hitpoints member */
void GameObject::UpdateHP() {
    hpbar_.setScale(sf::Vector2f(float((hitpoints_ / max_hitpoints_)), 1));
}

/* Move player character on the scene and check collisions. */
void GameObject::Move(PhysicsVector direction) {
    if (direction.Length() > 0) {
        Accelerate(DirectionOfVector(direction));
    }
    else if (GetVelocity().Length() > 0) {
        Decelerate(g_friction);
    }
    else {
        return;
    }
}

/* Check if player is colliding with items and change movement according to that */
bool GameObject::CheckCollisions(std::vector<GameObject*> objects) {
    /* hitbox rect of player */
    sf::Rect rect = GetRect();
    sf::Vector2f position = GetRectPosition();

    for (GameObject* obj : objects) {
        if (obj->collidable_) {
            sf::Rect obj_rect = obj->GetRect();
            sf::Vector2f obj_pos = obj->GetPosition();

            if (obj_rect.contains(position + PhysicsVector(0,0) + GetVelocity())) {
                if (obj_pos.y + obj_rect.height <= position.y) {
                    SetYVelocity(0);
                }
                else if (obj_pos.x + obj_rect.width <= position.x) {
                    SetXVelocity(0);
                }
            }
            if (obj_rect.contains(position + PhysicsVector(rect.width,0) + GetVelocity())) {
                if (obj_pos.x >= position.x + rect.width) {
                    SetXVelocity(0);
                }
                else if (obj_pos.y + obj_rect.height <= position.y) {
                    SetYVelocity(0);
                }
            }
            if (obj_rect.contains(position + PhysicsVector(0,rect.height) + GetVelocity())) {
                if (obj_pos.y >= position.y + rect.height) {
                    SetYVelocity(0);
                }
                else if (obj_pos.x + obj_rect.width <= position.x) {
                    SetXVelocity(0);
                }
            }
            if (obj_rect.contains(position + PhysicsVector(rect.width,rect.height) + GetVelocity())) {
                if (obj_pos.y >= position.y + rect.height) {
                    SetYVelocity(0);
                }
                else if (obj_pos.x >= position.x + rect.width) {
                    SetXVelocity(0);
                }
            }
        }
    }

    return false;
}

void GameObject::Heal(float amount) {
    hitpoints_ += amount;
    if (hitpoints_ > GetMaxHitPoints()) {
        hitpoints_ = GetMaxHitPoints();
    }
}

void GameObject::TakeDamage(float damage) {
    if (damage >= hitpoints_) {
        hitpoints_ = 0;
        collidable_ = false;
        if (GetType() != ENEMY) {
            dead_ = true;
        }
    }
    else {
        hitpoints_ -= damage;
    }
}

/* Set object sprite */
void GameObject::SetSprite(sf::Texture texture) {
    texture_ = &texture;
    sprite_.setTexture(*texture_);
}

/* Overload << operator for printing */
std::ostream& operator<<(std::ostream& os, GameObject obj) {
    os << "<" << obj.GetType() << ">";
    return os;
}
