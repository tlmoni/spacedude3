#pragma once

#include <iostream>
#include "../movement.hpp"

extern sf::RenderWindow* main_window;

/* Parent class for all game objects */
class GameObject : public Movement {
public:
    /* Constructor */
    GameObject(sf::Vector2f pos, std::string file, RectHitbox hitbox, std::string name = "GameObject", double max_speed = 5.f,
        double acceleration = 1.f, int hitpoints = 69, bool shootable = false, int damage = 0);

    /* Copy constructor */
    GameObject(const GameObject&);

    /* Copy assignment operator */
    GameObject& operator=(const GameObject&);

    /* Destructor */
    virtual ~GameObject();

    /* Sets position of the object and its sprite */
    void SetPosition(sf::Vector2f new_pos);

    /* Set object origin */
    void SetOrigin(float x, float y);

    /* Set object rotation */
    void SetRotation(PhysicsVector direction);

    /* Set new hitbox for GameObject */
    void SetHitbox(RectHitbox hitbox);

    /* Function resposible for updating player character position */
    void Move(PhysicsVector direction);

    /* Action for enemies etc. */
    virtual void Action(PhysicsVector, std::vector<GameObject*>) { }

    /* Action for player etc. */
    template <typename T>
    T* Action(std::vector<GameObject*>) { }

    /* Check if player is colliding with items and change movement according to that */
    virtual void CheckCollisions(std::vector<GameObject*> objects);

    std::string GetName() { return name_; }
    PhysicsVector GetPosition() { return pos_; }
    sf::Sprite GetSprite() { return sprite_; }
    sf::FloatRect GetRect() { return hitbox_.getGlobalBounds(); }
    PhysicsVector GetRectPosition() { return hitbox_.getPosition() - hitbox_.getOrigin(); }
    sf::RectangleShape GetHitbox() { return hitbox_; }
    sf::Texture* GetTexture() { return texture_; }
    int& GetHitPoints() { return hitpoints_; }
    bool IsShootable() { return shootable_; }
    int GetDamage() { return damage_; }

    sf::Clock deadtimer_; // Timer for tracking how long has object been dead
    bool dead_ = false; // Indicates if the object is dead or alive
private:
    std::string name_;
    PhysicsVector pos_;
    sf::Sprite sprite_;
    sf::Texture* texture_;
    RectHitbox hitbox_;
    int damage_; // Damage for gameobject
    int hitpoints_;
    bool shootable_;
};

/* Overload << operator for printing */
std::ostream& operator<<(std::ostream& os, PhysicsVector vector);
