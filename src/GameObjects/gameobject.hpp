#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "../movement.hpp"

/* Parent class for all game objects */
class GameObject {
public:
    GameObject(sf::Vector2f pos);

    /* Sets position of the object and it's sprite */
    void SetPosition(sf::Vector2f new_pos);

    sf::Vector2f GetPosition() { return pos_; }
    sf::Sprite& GetSprite() { return sprite_; }

private:
    // Hitbox hitbox;
    sf::Vector2f pos_; /* Variable tracking player position the scene */
    sf::Sprite sprite_; /* Variable to hold player sprite */
    sf::Texture texture_;
    // Movement movement_;
};