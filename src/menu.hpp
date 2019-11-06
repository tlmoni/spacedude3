#pragma once

#include "SFML/Graphics.hpp"
#include "constants.hpp"

enum MenuButtons {
    PLAY,
    SETTINGS,
    EXIT
};

/* Class description */
class Menu {
public:
    /* Constructor */
    Menu(float width, float height, sf::RenderWindow* window);

    /* Default destructor */
    ~Menu() = default;

    /* Method description */
    void Draw(sf::RenderWindow* window);

    /* Method description */
    void Move_Up();

    /* Method description */
    void Move_Down();

private:
    int selected_menu_item_; // Description
    sf::RenderWindow* window_; // Desscription
    sf::Sprite mainmenu_[NUMBER_OF_MENU_ITEMS]; // Description
};
