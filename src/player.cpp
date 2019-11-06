#include "player.hpp"

extern Scene* scene;

Player::Player(sf::Vector2f pos) : GameObject(pos) {
    // Get enum parameter as what character the player chose and load that characters information
    sf::RectangleShape& sprite = GetSprite();
    sprite.setSize(sf::Vector2f(30.0f,30.0f));
    sprite.setPosition(sf::Vector2f(pos));
    sprite.setFillColor(sf::Color::Cyan);

    /* TODO: Implement player sprite initialization with actual models */
}

/* Handle player movement and events, update these to the scene */
void Player::Loop() {

    /* Clear the content of the previous scene */
    main_window->clear();

    /* Draw the player sprite */
    main_window->draw(GetSprite());

    /* Render the scene */
    scene->Render();

    /* Main loop to handle player actions on the scene */
    while (main_window->isOpen()) {
        sf::Event event; /* Varibale tracking events affecting the main_window */

        /* Checks if the main_window has closed */
        main_window->pollEvent(event);
        if (event.type == sf::Event::Closed) {
            main_window->close();
        }

        /* Checking if player action has occurred */
        bool action = Action();
        /* If actions did take place, clear, draw & render the changes to the scene */
        if (action) {
            main_window->clear(); 
            main_window->draw(GetSprite());
            scene->Render();
        }
    }
}

/* Function handling keypress and their effects on player character */
bool Player::Action() {

    sf::Vector2f pos_dif = sf::Vector2f(0.0f, 0.0f); /* Variable tracking amount of movement made */
    bool moved = false; /* Variable tracking IF movement was made */

    /* Conditional structures for tracking which keys were pressed and updating player actions accordingly */

    /* Movement to the left */
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        pos_dif += sf::Vector2f(-0.5f, 0.0f);
        moved = true;
    }

    /* Movement to the right */
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        pos_dif += sf::Vector2f(0.5f, 0.0f);
        moved = true;
    }

    /* Movement forward */
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        pos_dif += sf::Vector2f(0.0f, -0.5f);
        moved = true;
    }

    /* Movement to backward */
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        pos_dif += sf::Vector2f(0.0f, 0.5f);
        moved = true;
    }
    /* Call to move funtion which updates player position IF any movement was made */
    if (moved) {
        Move(pos_dif);
    }

    return moved;
}

/* Move player character on the scene */
void Player::Move(sf::Vector2f pos_dif) {
    /* Add position difference incurred by movement to player position */
    SetPosition(GetPosition() + pos_dif);
}
