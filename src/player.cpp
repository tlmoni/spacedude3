#include "player.hpp"

/* Constructor. Get parameter for what character player chose. */
Player::Player(Character* character, sf::Vector2f pos) :
GameObject(pos, character->GetTextureFile(), character->GetHitBox(), PLAYER, character->GetMaxSpeed(), character->GetAcceleration(),
character->GetDamage(), character->GetHP(), true, character->GetAttackDelay()) {
    // Origin and camera
    SetOrigin(character->GetOrigin().x, character->GetOrigin().y);
    player_cam_.setCenter(GetPosition());

    // Sounds
    if (!buffer_.loadFromFile("src/Audio/Sound/sound_gun.ogg")) {
        std::cout << "ERROR: Loading gun sound failed!" << std::endl;
    }
    if (!deathbuffer_.loadFromFile("src/Audio/Sound/sound_playerdeath.ogg")) {
        std::cout << "ERROR: Loading player death sound failed!" << std::endl;
    }
    death_.setBuffer(deathbuffer_);
    gunshot_.setBuffer(buffer_);
    gunshot_.setVolume(80);

    weapon_ = blaster;
    speed_ = character->GetMaxSpeed();

    // Animations
    std::map<int, std::pair<int, int>> animations;
    animations[MOVE] = std::pair<int, int>(0, 2);
    animations[ANIM1] = std::pair<int, int>(0, 4);
    animations[ANIM2] = std::pair<int, int>(0, 3);
    animations[ANIM3] = std::pair<int, int>(0, 1);

    sprite_legs_.setPosition(GetPosition());
    sprite_weapon_.setPosition(GetPosition());

    animation_ = Animation("src/Textures/player.png", animations, 64, 250, 50, 333);
    sprite_legs_ = animation_.Stop(MOVE);
    sprite_weapon_ = animation_.Stop(ANIM1);
    sprite_legs_.setOrigin(26,32);
    sprite_weapon_.setOrigin(26,32);
}

/* Handle keypress and their effects on player character */
std::vector<Projectile*> Player::Action(std::vector<GameObject*> objects) {

    PhysicsVector dir_vector = PhysicsVector(0.0f, 0.0f);
    std::vector<Projectile*> projectiles;

    // Handle bullet spawning and setting of initial speed
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && attack_timer_.getElapsedTime().asMilliseconds() > weapon_.shoot_delay) {
        attack_timer_.restart();
        Shoot();

        if (sound_on) {
            gunshot_.play();
        }

        projectiles = Shoot();
    }
    else {
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

        //Switch weapons from number buttons
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
            SwitchWeapon(BLASTER);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
            SwitchWeapon(SHOTGUN);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
            SwitchWeapon(BANDAGE);
        }

        if (attack_timer_.getElapsedTime().asMilliseconds() > weapon_.shoot_delay) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
                SetMaxSpeed(1.5*speed_);
            }
            else {
                SetMaxSpeed(speed_);
            }

            if (weapon_.type == BLASTER) {
            sprite_weapon_ = animation_.Stop(ANIM1);
            }
            else if (weapon_.type == SHOTGUN) {
                sprite_weapon_ = animation_.Stop(ANIM2);
            }
        }
        else {
            if (weapon_.type == BLASTER) {
                sprite_weapon_ = animation_.NextFrame(ANIM1);
            }
            else if (weapon_.type == SHOTGUN) {
                sprite_weapon_ = animation_.NextFrame(ANIM2);
            }
        }
    }

    Move(dir_vector);
    if (GetVelocity().Length() != 0) {
        sprite_legs_ = animation_.NextFrame(MOVE);
    }
    else {
        sprite_legs_ = animation_.Stop(MOVE);
    }

    CheckCollisions(objects);
    SetPosition(GetPosition() + GetVelocity());
    Rotate();

    player_cam_.setCenter(GetPosition());
    main_window->setView(GetView());

    return projectiles;
}

std::vector<Projectile*> Player::Shoot() {
    std::vector<Projectile*> projectiles;
    if (weapon_.type == BLASTER) {
        SetMaxSpeed(0.5*speed_);
        sprite_weapon_ = animation_.NextFrame(ANIM1);

        Projectile* bullet = new Projectile(GetPosition(), GetType(), weapon_.bullet);
        PhysicsVector direction = GetCurrentCursorDirection();
        int bullet_angle = rand() % 20;
        direction.Rotate(bullet_angle-10);

        PhysicsVector vel = GetVelocity().UnitVector();
        SetVelocity(vel.Scale(0.5f));
        direction = PhysicsVector(direction.x * bullet->GetMaxSpeed()/sqrt(2), direction.y * bullet->GetMaxSpeed()/sqrt(2));
        bullet->SetVelocity(direction + GetVelocity());
        projectiles.push_back(bullet);
    }
    else if (weapon_.type == SHOTGUN) {
        sprite_weapon_ = animation_.NextFrame(ANIM2);
        SetMaxSpeed(0.7*speed_);
        for (int i = -2; i < 3; i++) {
            Projectile* bullet = new Projectile(GetPosition(), GetType(), weapon_.bullet);
            PhysicsVector direction = GetCurrentCursorDirection();
            direction.Rotate(i*15);

            PhysicsVector vel = GetVelocity().UnitVector();
            SetVelocity(vel.Scale(0.01f));

            direction = PhysicsVector(direction.x * bullet->GetMaxSpeed()/sqrt(2), direction.y * bullet->GetMaxSpeed()/sqrt(2));
            bullet->SetVelocity(direction + GetVelocity());
            projectiles.push_back(bullet);
        }
    }
    else if (weapon_.type == BANDAGE) {
        sprite_weapon_ = animation_.Stop(ANIM3);
        SetMaxSpeed(speed_);

        Projectile* bullet = new Projectile(GetPosition(), GetType(), weapon_.bullet);
        PhysicsVector direction = GetCurrentCursorDirection();

        PhysicsVector vel = GetVelocity().UnitVector();
        SetVelocity(vel.Scale(0.01f));
        direction = PhysicsVector(direction.x * bullet->GetMaxSpeed()/sqrt(2), direction.y * bullet->GetMaxSpeed()/sqrt(2));
        bullet->SetVelocity(direction + GetVelocity());
        projectiles.push_back(bullet);

        Heal(8);
    }

    return projectiles;
}

void Player::SwitchWeapon(int weapon_type) {
    if (weapon_type == BLASTER) {
        if (!buffer_.loadFromFile("src/Audio/Sound/sound_gun.ogg")) {
            std::cout << "ERROR: Loading gun sound failed!" << std::endl;
        }
        weapon_ = blaster;
        sprite_weapon_ = animation_.Stop(ANIM1);
    }
    else if (weapon_type == SHOTGUN) {
        if (!buffer_.loadFromFile("src/Audio/Sound/sound_shotgun.ogg")) {
            std::cout << "ERROR: Loading gun sound failed!" << std::endl;
        }
        weapon_ = shotgun;
        sprite_weapon_ = animation_.Stop(ANIM2);
    }
    else if (weapon_type == BANDAGE) {
        if (!buffer_.loadFromFile("src/Audio/Sound/sound_heal.ogg")) {
            std::cout << "ERROR: Loading gun sound failed!" << std::endl;
        }
        weapon_ = bandage;
        sprite_weapon_ = animation_.Stop(ANIM3);
    }
}

/* Rotate player */
void Player::Rotate() {
    sf::Vector2f direction = GetCurrentCursorDirection(); // Get current mouse direction, relative to the player.
    SetRotation(direction); // Rotate the player sprite into new position.
    sprite_legs_.setRotation(std::atan2(direction.y, direction.x) * 180 / M_PI);
    sprite_weapon_.setRotation(std::atan2(direction.y, direction.x) * 180 / M_PI);
}

/* Function that calculates current mousewise direction of the player sprite
   Returns the direction of the player */
PhysicsVector Player::GetCurrentCursorDirection() {
    sf::Vector2i cursor = sf::Mouse::getPosition(*main_window); // Get the mouse position on main window in pixels
    sf::Vector2f worldCursor = main_window->mapPixelToCoords(cursor); // Get the mouse position in world coordinates
    sf::Vector2f direction = worldCursor - GetPosition(); // Get the relative direction
    return PhysicsVector(direction).UnitVector();
}

/* Play player death sound and set loop true */
void Player::PlayDeathSound() {
    death_.setLoop(true);
    death_.play();
}

/* Stop player death sound and set loop false */
void Player::StopDeathSound() {
    death_.setLoop(false);
    death_.stop();
}

/* Draws all player sprites to main_window(global) */
void Player::Draw() {
    sprite_legs_.setPosition(GetPosition());
    sprite_weapon_.setPosition(GetPosition());
    main_window->draw(sprite_legs_);
    main_window->draw(sprite_weapon_);
    main_window->draw(GetSprite());

    main_window->draw(GetHPBackground());
    main_window->draw(GetHPBar());
}