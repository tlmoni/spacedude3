#include <cmath>
#include "player.hpp"

/* Constructor. Get parameter for what character player chose. */
Player::Player(Character* character, sf::Vector2f pos) :
GameObject(pos, character->GetTextureFile(), character->GetHitBox(), character->GetIdentity()),
Movement(character->GetMaxSpeed(), character->GetAcceleration()),
character_(character) {

    SetOrigin(38.f,47.f);
    player_cam_.setCenter(GetPosition());
}

Player::~Player() {
    delete character_;
    for(Projectile* p : projectiles_) {
        delete p;
    }
}

/* Handle keypress and their effects on player character */
std::vector<Projectile*> Player::Action() {

    PhysicsVector dir_vector = PhysicsVector(0.0f, 0.0f);
    std::vector<Projectile*> projectiles;

    // Movement to the left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        dir_vector += PhysicsVector(-1.0f, 0.0f);
    }

    // Movement to the right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        dir_vector += PhysicsVector(1.0f, 0.0f);
    }

    // Movement Projectile* bullet = new Projectile(GetPosition());up
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        dir_vector += PhysicsVector(0.0f, -1.0f);
    }

    // Movement down
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        dir_vector += PhysicsVector(0.0f, 1.0f);
    }

    Move(dir_vector);
    Rotate();


    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        Projectile* bullet = new Projectile(GetPosition());
        PhysicsVector direction = GetCurrentCursorDirection();
        bullet->SetVelocity(direction.x * bullet->GetSpeed()/sqrt(2), direction.y * bullet->GetSpeed()/sqrt(2));
        projectiles.push_back(bullet);

    }

    player_cam_.setCenter(GetPosition());
    main_window->setView(GetView());

    return projectiles;
}

/* Move player character on the scene and check collisions. */
void Player::Move(PhysicsVector dir_vector) {

    if (LengthOfVector(dir_vector) > 0) {
        Accelerate(DirectionOfVector(dir_vector));
    }
    else if (GetVelocity().Length() > 0) {
        Decelerate(g_friction);
    }
    else {
        return;
    }

    CheckCollisions();

    SetPosition(GetPosition() + GetVelocity());
}

/* Check if player is colliding with items and change movement according to that */
void Player::CheckCollisions() {
    /* hitbox rect of player */
    sf::Rect rect = GetRect();
    sf::Vector2f position = GetRectPosition();

    PhysicsVector velocity = GetVelocity();

    for (GameObject* obj : scene->GetObjects()) {
        sf::Rect obj_rect = obj->GetRect();
        sf::Vector2f obj_pos = obj->GetPosition();

        if (obj_rect.contains(position + PhysicsVector(0,0) + velocity)) {
            if (obj_pos.x + obj_rect.width <= position.x) {
                SetXVelocity(0);
            }
            if (obj_pos.y + obj_rect.height <= position.y) {
                SetYVelocity(0);
            }
        }
        if (obj_rect.contains(position + PhysicsVector(rect.width,0) + velocity)) {
            if (obj_pos.x >= position.x + rect.width) {
                SetXVelocity(0);
            }
            if (obj_pos.y + obj_rect.height <= position.y) {
                SetYVelocity(0);
            }
        }
        if (obj_rect.contains(position + PhysicsVector(0,rect.height) + velocity)) {
            if (obj_pos.x + obj_rect.width <= position.x) {
                SetXVelocity(0);
            }
            if (obj_pos.y >= position.y + rect.height) {
                SetYVelocity(0);
            }
        }
        if (obj_rect.contains(position + PhysicsVector(rect.width,rect.height) + velocity)) {
            if (obj_pos.x >= position.x + rect.width) {
                SetXVelocity(0);
            }
            if (obj_pos.y >= position.y + rect.height) {
                SetYVelocity(0);
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
PhysicsVector Player::GetCurrentCursorDirection() {
    sf::Vector2i cursor = sf::Mouse::getPosition(*main_window); // Get the mouse position on main window in pixels
    sf::Vector2f worldCursor = main_window->mapPixelToCoords(cursor); // Get the mouse position in world coordinates
    sf::Vector2f direction = worldCursor - GetPosition(); // Get the relative direction
    return PhysicsVector(direction).UnitVector();
}
