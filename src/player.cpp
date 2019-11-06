#include <cmath>
#include "player.hpp"

extern Scene* scene;

Player::Player(sf::Vector2f pos) : pos_(pos), direction_(DEFAULT), direction_cursor_(GetCurrentDirection()) {

    // TODO: Get enum parameter as what character the player chose and load that characters information

    sprite_.setPosition(sf::Vector2f(pos)); // Set the player sprite position on the scene
    sprite_.setOrigin(95.f,119.f); // Set player sprite origin point, around which it will be rotated.

    /* UNDER CONSTRUCTION: Implement player sprite initialization with actual models */

    // Load texture for player sprite, with bubblegum error check
    if (!texture_basic_.loadFromFile("src/Textures/duderino.png")){
        texture_basic_.loadFromFile("src/Textures/error.png");
    }
    texture_size_ = texture_basic_.getSize(); // Set the texture size.
    sprite_.setTexture(texture_basic_); // Set the loaded texture into the player sprite.

    /* UNDER CONSTRUCTION END */
}

/* Handle player movement and events, update these to the scene */
void Player::Loop() {

    main_window->clear(); // Clear the content of the previous scene
    main_window->draw(sprite_);
    scene->Render();

    // Main loop to handle player actions on the scene
    while (main_window->isOpen()) {
        sf::Event event; // Varibale tracking events affecting the main_window

        // Checks if the main_window has closed
        main_window->pollEvent(event);
        if (event.type == sf::Event::Closed) {
            main_window->close();
        }

        // Checking if player action has occurred
        bool action = Action();
        // If actions did take place, clear, draw & render the changes to the scene
        if (action) {
            main_window->clear();
            main_window->draw(sprite_);
            scene->Render();
        }
    }
}

/* Function handling keypress and their effects on player character */
bool Player::Action() {

    sf::Vector2f pos_dif = sf::Vector2f(0.0f, 0.0f); // Variable tracking amount of movement made
    bool moved = false; // Variable tracking IF movement was made

    /* Conditional structures for tracking which keys were pressed and updating player actions accordingly */

    // Movement to the left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        pos_dif += sf::Vector2f(-0.5f, 0.0f);
        moved = true;
    }

    // Movement to the right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        pos_dif += sf::Vector2f(0.5f, 0.0f);
        moved = true;
    }

    // Movement forward
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        pos_dif += sf::Vector2f(0.0f, -0.5f);
        moved = true;
    }

    // Movement to backward
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        pos_dif += sf::Vector2f(0.0f, 0.5f);
        moved = true;
    }

    /* UNDER CONSTRUCTION: Checking IF the mouse has been moved */

    if (GetCurrentDirection() != direction_cursor_) {
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

    pos_ += pos_dif; // Add position difference incurred by movement to player position

    /* UNDER CONSTRUCTION: KEYBOARD conditions for tracking & changing the direction of player sprite */
    /*
    // Set to face left
    if(pos_dif.x < 0 && direction_ != LEFT){
        sprite_.setRotation(-180);
        direction_ = LEFT;
    }

    // Set to face right
    if(pos_dif.x > 0 && direction_ != RIGHT){
        sprite_.setRotation(0);
        direction_ = RIGHT;
    }

    // Set to face upwards
    if(pos_dif.y > 0 && direction_ != UP){
        sprite_.setRotation(90);
        direction_ = UP;
    }

    // Set to face downwards
    if(pos_dif.y < 0 && direction_ != DOWN){
        sprite_.setRotation(-90);
        direction_ = DOWN;
    }
    */

    /* UNDER CONSTRUCTION: MOUSE conditions for tracking & changing the direction of player sprite  */

    sf::Vector2f direction = GetCurrentDirection();
    sprite_.setRotation(std::atan2(direction.y, direction.x) * 180 / M_PI);

    /* UNNDER CONSTRUCTION END */

    sprite_.setPosition(pos_); // Set the player sprite position on the scene

}

/* UNDER CONSTRUCTION: Getting current mouse coordinates on main window */

/* Function that calculates current mousewise direction of the player sprite */
sf::Vector2f Player::GetCurrentDirection(){
    sf::Vector2i cursor = sf::Mouse::getPosition(*main_window); // Get the mouse position on main window in pixels
    sf::Vector2f worldCursor = main_window->mapPixelToCoords(cursor); // Get the mouse position in world coordinates
    sf::Vector2f direction = worldCursor - GetPosition(); // Get the relative direction
    return direction;
}

/*UNDER CONSTRUCTION END*/