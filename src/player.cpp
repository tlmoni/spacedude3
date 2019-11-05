

#include "player.hpp"

extern Scene* scene;

Player::Player(sf::Vector2f pos) : pos_(pos) {
    // Get enum parameter as what character the player chose and load that characters information
    sprite_.setSize(sf::Vector2f(10.0f,10.0f));
    sprite_.setPosition(sf::Vector2f(pos));
    sprite_.setFillColor(sf::Color::Cyan);
}


/* Handle player movement and events, update these to the scene */
void Player::Loop() {

    main_window->clear();
    main_window->draw(sprite_);
    scene->Render();

    while(main_window->isOpen()) {
        sf::Event event;
        main_window->pollEvent(event);
        if (event.type == sf::Event::Closed) {
            main_window->close();
        }

        bool action = Action();
        if (action) {
            main_window->clear();
            main_window->draw(sprite_);
            scene->Render();
        }

    }

}

bool Player::Action() {

    sf::Vector2f pos_dif = sf::Vector2f(0.0f, 0.0f);
    bool moved = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        pos_dif += sf::Vector2f(-0.5f, 0.0f);
        moved = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        pos_dif += sf::Vector2f(0.5f, 0.0f);
        moved = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        pos_dif += sf::Vector2f(0.0f, -0.5f);
        moved = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        pos_dif += sf::Vector2f(0.0f, 0.5f);
        moved = true;
    }
    if (moved) {
        Move(pos_dif);
    }

    return moved;
}

/* move the player position */
void Player::Move(sf::Vector2f pos_dif) {

    pos_ += pos_dif;
    sprite_.setPosition(pos_);

}