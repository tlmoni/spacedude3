#include <cmath>
#include "player.hpp"


/* Constructor. Get parameter for what character player chose. */
Player::Player(sf::Vector2f pos, std::string identity, RectHitbox hitbox) : GameObject(pos, identity, hitbox, "Player") {
    movement_ = Movement(7.0f, 1.5f);

    SetOrigin(38.f,47.f);
    player_cam_.setCenter(GetPosition());
}

/* Handle keypress and their effects on player character */
bool Player::Action() {

    PhysicsVector dir_vector = PhysicsVector(0.0f, 0.0f);
    bool action;

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

    return action;
}

/* Move player character on the scene and check collisions. */
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

    CheckCollisions();

    SetPosition(GetPosition() + movement_.GetVelocity());

    return true;
}

/* Check if player is colliding with items and change movement according to that */
void Player::CheckCollisions() {
    /* hitbox rect of player */
    sf::Rect rect = GetRect();
    sf::Vector2f position = GetRectPosition();

    PhysicsVector velocity = movement_.GetVelocity();

    for (GameObject* obj : scene->GetObjects()) {
        sf::Rect obj_rect = obj->GetRect();
        sf::Vector2f obj_pos = obj->GetPosition();

        if (obj_rect.contains(position + PhysicsVector(0,0) + velocity)) {
            if (obj_pos.x + obj_rect.width <= position.x) {
                movement_.SetXVelocity(0);
            }
            if (obj_pos.y + obj_rect.height <= position.y) {
                movement_.SetYVelocity(0);
            }
        }
        if (obj_rect.contains(position + PhysicsVector(rect.width,0) + velocity)) {
            if (obj_pos.x >= position.x + rect.width) {
                movement_.SetXVelocity(0);
            }
            if (obj_pos.y + obj_rect.height <= position.y) {
                movement_.SetYVelocity(0);
            }
        }
        if (obj_rect.contains(position + PhysicsVector(0,rect.height) + velocity)) {
            if (obj_pos.x + obj_rect.width <= position.x) {
                movement_.SetXVelocity(0);
            }
            if (obj_pos.y >= position.y + rect.height) {
                movement_.SetYVelocity(0);
            }
        }
        if (obj_rect.contains(position + PhysicsVector(rect.width,rect.height) + velocity)) {
            if (obj_pos.x >= position.x + rect.width) {
                movement_.SetXVelocity(0);
            }
            if (obj_pos.y >= position.y + rect.height) {
                movement_.SetYVelocity(0);
            }
        }

    }
}

/* Rotate player */
void Player::Rotate() {
    sf::Vector2f direction = GetCurrentCursorDirection(); // Get current mouse direction, relative to the player.
    SetRotation(direction.x, direction.y); // Rotate the player sprite into new position.
}

/* Function that calculates current mousewise direction of the player sprite
   Returns the direction of the player */
sf::Vector2f Player::GetCurrentCursorDirection() {
    sf::Vector2i cursor = sf::Mouse::getPosition(*main_window); // Get the mouse position on main window in pixels
    sf::Vector2f worldCursor = main_window->mapPixelToCoords(cursor); // Get the mouse position in world coordinates
    sf::Vector2f direction = worldCursor - GetPosition(); // Get the relative direction
    return direction;
}

