#include "player.hpp"

extern Scene* scene;
extern sf::Time time_per_frame;

/* Constructor. Get parameter for what character player chose. */
Player::Player(sf::Vector2f pos) : GameObject(pos) {
    movement_ = Movement(9.0f, 3.0f);

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
    main_window->clear();
    main_window->draw(GetSprite());

    main_window->setFramerateLimit(60);

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
            main_window->draw(GetSprite());


            scene->Render();
        }
        
    
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

    action = Move(dir_vector);
    // Call to move funtion which updates player position IF any movement was made
    return action;
}

/* Move player character on the scene */
bool Player::Move(sf::Vector2f dir_vector) {
    
    if (LengthOfVector(dir_vector) > 0) {
        movement_.Accelerate(DirectionOfVector(dir_vector));
    }
    else if (movement_.GetVelocity().Length() > 0) {
        movement_.Decelerate();
    }
    
    SetPosition(GetPosition() + movement_.GetVelocity());
    sprite_.setPosition(GetPosition() + movement_.GetVelocity());
    
    
    return true;
}
