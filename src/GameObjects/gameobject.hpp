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
    ~GameObject();

    /* Sets position of the object and its sprite */
    void SetPosition(sf::Vector2f new_pos);

    /* Set object origin */
    void SetOrigin(float x, float y);

    /* Set object rotation */
    void SetRotation(float x, float y);

    /* Set new hitbox for GameObject */
    void SetHitbox(RectHitbox hitbox);

    /* Check if player is colliding with items and change movement according to that */
    void CheckCollisions(std::vector<GameObject*> objects);

    std::string GetName() { return name_; }
    sf::Vector2f GetPosition() { return pos_; }
    sf::Sprite GetSprite() { return sprite_; }
    sf::FloatRect GetRect() { return hitbox_.getGlobalBounds(); }
    sf::Vector2f GetRectPosition() { return hitbox_.getPosition() - hitbox_.getOrigin(); }
    sf::RectangleShape GetHitbox() { return hitbox_; }
    sf::Texture* GetTexture() { return texture_; }
    int GetDamage() { return damage_; }
    int GetHitPoints() { return hitpoints_; }

    sf::Clock deadtimer_; // Timer for tracking how long has object been dead
    bool dead_ = false; // Indicates if the object is dead or alive
private:
    std::string name_;
    sf::Vector2f pos_; // Variable tracking player position in the scene
    sf::Sprite sprite_; // Variable to hold player sprite
    sf::Texture* texture_;
    RectHitbox hitbox_;
    int damage_; // Damage for gameobject
    int hitpoints_;
    bool shootable_;
};

/* Overload << operator for printing */
std::ostream& operator<<(std::ostream& os, PhysicsVector vector);
