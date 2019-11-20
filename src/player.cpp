#include <cmath>
#include "player.hpp"

extern Scene* scene;

/* Constructor. Get parameter for what character player chose. */
Player::Player(sf::Vector2f pos, std::string identity) : GameObject(pos, identity) {
    movement_ = Movement(9.0f, 1.5f);

    sf::Sprite sprite = GetSprite();
    sprite.setPosition(sf::Vector2f(pos)); // Set the player sprite position on the scene
    sprite.setOrigin(95.f, 119.f); // Set player sprite origin point, around which it will be rotat

    SetOrigin(38.f,47.f);
    player_cam_.setCenter(GetPosition());
}

/* Handle player movement and events, update these to the scene */
void Player::Loop() {

    main_window->clear();
    main_window->draw(GetSprite());
    /* BUBBLEGUM: Map drawing */
    main_window->draw(map->GetSprite());
    main_window->setView(GetView());

    scene->Render();

    // Main loop to handle player actions on the scene
    while (main_window->isOpen()) {
        sf::Event event; // Varibale tracking events affecting the main_window

        // Checks if the main_window has been closed

        main_window->pollEvent(event);
        if (event.type == sf::Event::Closed) {
            main_window->close();
        }

        // Checking if player action has occurred
        bool action = Action();
        // If actions did take place, clear, draw & render the changes to the scene
        if (action) {
            main_window->clear(); 
            main_window->draw(GetSprite());

            /* BUBBLEGUM: Map drawing */
            /* Miks tämä on täällä :D */
            main_window->draw(map->GetSprite());
            /* BUBBLEGUM END */

            main_window->draw(GetSprite());
            scene->Render();
            //std::cout << movement_.GetVelocity() << std::endl;
        }
        player_cam_.setCenter(GetPosition());
        main_window->setView(GetView());
    }
}

/* Function handling keypress and their effects on player character */
bool Player::Action() {

    sf::Vector2f dir_vector = sf::Vector2f(0.0f, 0.0f);
    bool action;
    /* Conditional structures for tracking which keys were pressed and updating player actions accordingly */

    // Movement to the left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        dir_vector += sf::Vector2f(-1.0f, 0.0f);
    }

    // Movement to the right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        dir_vector += sf::Vector2f(1.0f, 0.0f);
    }

    // Movement forward
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        dir_vector += sf::Vector2f(0.0f, -1.0f);
    }

    // Movement to backward
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        dir_vector += sf::Vector2f(0.0f, 1.0f);
    }

    if (GetCurrentCursorDirection() != direction_cursor_) {
        action = true;
    }

    action = Move(dir_vector);
    Rotate();
    
    // Call to move funtion which updates player position IF any movement was made
    return true;
}

/* Move player character on the scene */
bool Player::Move(sf::Vector2f dir_vector) {
    
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

