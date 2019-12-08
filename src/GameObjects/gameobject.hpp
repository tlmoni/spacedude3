#pragma once

#include <iostream>
#include "../movement.hpp"

extern sf::RenderWindow* main_window;

enum Type {
    OBJECT,
    ENEMY,
    PLAYER,
    WALL,
    BULLET
};

/* Parent class for all game objects */
class GameObject : public Movement {
public:
    /* Constructor */
    GameObject(sf::Vector2f pos, std::string file, RectHitbox hitbox, int type = OBJECT, std::string name = "GameObject", double max_speed = 5.f,
        double acceleration = 1.f, float hitpoints = 69, bool shootable = false, int damage = 0);

    /* Copy constructor */
    GameObject(const GameObject&);

    /* Copy assignment operator */
    GameObject& operator=(const GameObject&);

    /* Destructor */
    virtual ~GameObject();

    /* Sets position of the object and its sprite */
    void SetPosition(PhysicsVector new_pos);

    /* Set object origin */
    void SetOrigin(float x, float y);

    /* Set object rotation */
    void SetRotation(PhysicsVector direction);

    /* Set new hitbox for GameObject */
    void SetHitbox(RectHitbox hitbox);

    /* Handle hpbar updating with hitpoints member */
    void UpdateHP();
    /* Function resposible for updating player character position */
    void Move(PhysicsVector direction);

    /* Action for enemies etc. */
    virtual void Action(PhysicsVector, std::vector<GameObject*>) { }

    /* Action for player etc. */
    template <typename T>
    T* Action(std::vector<GameObject*>) { }

    /* Check if player is colliding with items and change movement according to that */
    virtual void CheckCollisions(std::vector<GameObject*> objects);

    /* Take damage */
    void TakeDamage(float damage);

    std::string GetName() { return name_; }
    PhysicsVector GetPosition() { return pos_; }
    sf::Sprite GetSprite() { return sprite_; }
    sf::FloatRect GetRect() { return hitbox_.getGlobalBounds(); }
    PhysicsVector GetRectPosition() { return hitbox_.getPosition() - hitbox_.getOrigin(); }
    sf::RectangleShape GetHitbox() { return hitbox_; }
    sf::Texture* GetTexture() { return texture_; }
    sf::RectangleShape GetHPBar() { return hpbar_; }
    sf::RectangleShape GetHPBackground() { return hpbarbackground_; }
    int GetDamage() { return damage_; }
    float& GetHitPoints() { return hitpoints_; }
    float GetMaxHitPoints() { return max_hitpoints_; }
    bool IsShootable() { return shootable_; }
    int GetType() { return type_; }

    sf::Clock deadtimer_; // Timer for tracking how long has object been dead
    bool dead_ = false; // Indicates if the object is dead or alive
    bool collidable_ = true;
private:
    std::string name_;
    PhysicsVector pos_;
    sf::Sprite sprite_;
    sf::Texture* texture_;
    RectHitbox hitbox_;
    sf::RectangleShape hpbar_;
    sf::RectangleShape hpbarbackground_;
    int damage_; // Damage for gameobject
    float hitpoints_;
    float max_hitpoints_;
    bool shootable_;
    int type_;
};

/* Overload << operator for printing */
std::ostream& operator<<(std::ostream& os, PhysicsVector vector);
