#include "player.hpp"

/* Constructor. Get parameter for what character player chose. */
Player::Player(Character* character, sf::Vector2f pos) :
GameObject(pos, character->GetTextureFile(), character->GetHitBox(), character->GetIdentity(), character->GetMaxSpeed(), character->GetAcceleration()) {

    SetOrigin(character->GetOrigin().x, character->GetOrigin().y);
    player_cam_.setCenter(GetPosition());
    if (!buffer_.loadFromFile("src/Audio/Sound/sound_gun.ogg")) {
        std::cout << "ERROR: Loading gun sound failed!" << std::endl;
    }
    gunshot_.setBuffer(buffer_);
    gunshot_.setVolume(80);
}

/* Handle keypress and their effects on player character */
std::vector<Projectile*> Player::Action(std::vector<GameObject*> objects) {

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
    CheckCollisions(objects);
    SetPosition(GetPosition() + GetVelocity());
    Rotate();

    // Handle bullet spawning and setting of initial speed
    sf::Time time = reload_timer_.getElapsedTime();
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && time.asMilliseconds() > 140) {
        reload_timer_.restart();
        if (sound_on) {
            gunshot_.play();
        }
        Projectile* bullet = new Projectile(GetPosition());
        PhysicsVector direction = GetCurrentCursorDirection();
        direction = PhysicsVector(direction.x * bullet->GetSpeed()/sqrt(2), direction.y * bullet->GetSpeed()/sqrt(2));
        bullet->SetVelocity(direction + GetVelocity());
        projectiles.push_back(bullet);
    }

    player_cam_.setCenter(GetPosition());
    main_window->setView(GetView());

    return projectiles;
}

/* Move player character on the scene and check collisions. */
void Player::Move(PhysicsVector dir_vector) {

    if (dir_vector.Length() > 0) {
        Accelerate(DirectionOfVector(dir_vector));
    }
    else if (GetVelocity().Length() > 0) {
        Decelerate(g_friction);
    }
    else {
        return;
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
