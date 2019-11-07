#include <cmath>
#include "player.hpp"

extern Scene* scene;

/* Constructor. Get parameter for what character player chose. */
Player::Player(sf::Vector2f pos, std::string identity) : GameObject(pos, identity) {

    SetOrigin(38.f,47.f);
    player_cam_.setCenter(GetPosition());
}

/* Handle player movement and events, update these to the scene */
void Player::Loop() {

    main_window->clear();
    main_window->draw(GetSprite());
    scene->Render();
    main_window->setView(GetView());

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
            scene->Render();
        }
        main_window->setView(GetView());
    }
}


/* Function handling keypress and their effects on player character */
bool Player::Action() {

    sf::Vector2f pos_dif = sf::Vector2f(0.0f, 0.0f); // Variable tracking amount of movement made
    bool moved = false; // Variable tracking IF movement was made

    /* Conditional structures for tracking which keys were pressed and updating player actions accordingly */

    // Movement to the left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        pos_dif += sf::Vector2f(-0.25f, 0.0f);
        moved = true;
    }

    // Movement to the right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        pos_dif += sf::Vector2f(0.25f, 0.0f);
        moved = true;
    }

    // Movement forward
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        pos_dif += sf::Vector2f(0.0f, -0.25f);
        moved = true;
    }

    // Movement to backward
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        pos_dif += sf::Vector2f(0.0f, 0.25f);
        moved = true;
    }

    if (GetCurrentCursorDirection() != direction_cursor_) {
        moved = true;
    }

    /* UNDER CONSTRUCTION END */
    // Call to move funtion which updates player position IF any movement was made
    if (moved) {
        Move(pos_dif);
    }

    return moved;
}

/* Move player character on the scene */
void Player::Move(sf::Vector2f pos_dif) {

    sf::Vector2f direction = GetCurrentCursorDirection(); // Get current mouse direction, relative to the player.

    SetRotation(direction.x, direction.y); // Rotate the player sprite into new position.

    SetPosition(GetPosition() + pos_dif); // Add position difference incurred by movement to player position

    player_cam_.setCenter(GetPosition()); // Set the player sprite position on the scene
}

/* Function that calculates current mousewise direction of the player sprite */
sf::Vector2f Player::GetCurrentCursorDirection(){
    sf::Vector2i cursor = sf::Mouse::getPosition(*main_window); // Get the mouse position on main window in pixels
    sf::Vector2f worldCursor = main_window->mapPixelToCoords(cursor); // Get the mouse position in world coordinates
    sf::Vector2f direction = worldCursor - GetPosition(); // Get the relative direction
    return direction;
    // SOOOOS
}

