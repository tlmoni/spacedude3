#pragma once

#include <cmath>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "../movement.hpp"
#include "../recthitbox.hpp"

extern sf::RenderWindow* main_window;

/* Parent class for all game objects */
class GameObject {
public:
    GameObject() = default;
    GameObject(sf::Vector2f pos, std::string file, RectHitbox hitbox, std::string name = "GameObject");
    ~GameObject();

    /* Sets position of the object and its sprite */
    void SetPosition(sf::Vector2f new_pos);

    /* Set object origin */
    void SetOrigin(float x, float y);

    /* Set object rotation */
    void SetRotation(float x, float y);
    /* Set new hitbox for GameObject */
    void SetHitbox(RectHitbox hitbox);

    std::string GetName() { return name_; }
    sf::Vector2f GetPosition() { return pos_; }
    sf::Sprite* GetSprite() { return sprite_; }
    sf::FloatRect GetRect() { return hitbox_.getGlobalBounds(); }
    sf::Vector2f GetRectPosition() { return hitbox_.getPosition() - hitbox_.getOrigin(); }
    sf::RectangleShape GetHitbox() { return hitbox_; }
    sf::Texture* GetTexture() { return texture_; }

private:
    std::string name_;
    sf::Vector2f pos_; /* Variable tracking player position in the scene */
    sf::Sprite* sprite_; /* Variable to hold player sprite */
    sf::Texture* texture_;
    RectHitbox hitbox_;
};

/* Overload << operator for printing */
std::ostream& operator<<(std::ostream& os, PhysicsVector vector);