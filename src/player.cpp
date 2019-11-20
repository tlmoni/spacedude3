#include <cmath>
#include "player.hpp"

/* Constructor. Get parameter for what character player chose. */
Player::Player(sf::Vector2f pos, std::string identity) : GameObject(pos, identity) {
    movement_ = Movement(9.0f, 1.5f);

    sf::Sprite sprite = GetSprite();
    sprite.setPosition(sf::Vector2f(pos)); // Set the player sprite position on the scene
    sprite.setOrigin(95.f, 119.f); // Set player sprite origin point, around which it will be rotat

    SetOrigin(38.f,47.f);
    player_cam_.setCenter(GetPosition());
}



/* Function handling keypress and their effects on player character */
bool Player::Action() {

    PhysicsVector dir_vector = PhysicsVector(0.0f, 0.0f);
    bool action;
    /* Conditional structures for tracking which keys were pressed and updating player actions accordingly */

    // Movement to the left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        dir_vector += PhysicsVector(-1.0f, 0.0f);
    }

    // Movement to the right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        dir_vector += PhysicsVector(1.0f, 0.0f);
    }

    // Movement forward
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        dir_vector += PhysicsVector(0.0f, -1.0f);
    }

    // Movement to backward
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        dir_vector += PhysicsVector(0.0f, 1.0f);
    }

    if (GetCurrentCursorDirection() != direction_cursor_) {
        action = true;
    }

    action = Move(dir_vector);
    Rotate();
    player_cam_.setCenter(GetPosition());
    main_window->setView(GetView());
    
    // Call to move funtion which updates player position IF any movement was made
    return action;
}

/* Move player character on the scene */
bool Player::Move(PhysicsVector dir_vector) {
    
    if (LengthOfVector(dir_vector) > 0) {
        movement_.Accelerate(DirectionOfVector(dir_vector));
    }
    else if (movement_.GetVelocity().Length() > 0) {
        movement_.Decelerate();
    }
    else {
        return false;
    }

    SetPosition(GetPosition() + movement_.GetVelocity());

    return true;
}

void Player::Rotate() {
    sf::Vector2f direction = GetCurrentCursorDirection(); // Get current mouse direction, relative to the player.
    SetRotation(direction.x, direction.y); // Rotate the player sprite into new position.
}

/* Function that calculates current mousewise direction of the player sprite */
sf::Vector2f Player::GetCurrentCursorDirection() {
    sf::Vector2i cursor = sf::Mouse::getPosition(*main_window); // Get the mouse position on main window in pixels
    sf::Vector2f worldCursor = main_window->mapPixelToCoords(cursor); // Get the mouse position in world coordinates
    sf::Vector2f direction = worldCursor - GetPosition(); // Get the relative direction
    return direction;
}

