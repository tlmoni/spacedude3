#pragma once

#include "SFML/Graphics.hpp"
#include "constants.hpp"
#include "menubutton.hpp"

enum MenuButtons {
    PLAY,
    SETTINGS,
    EXIT
};

class Menu {
public:
    Menu(float width, float height, sf::RenderWindow* window);

    ~Menu() = default;

    void Draw(sf::RenderWindow* window);

    void Move_Up();

    void Move_Down();

private:
    int selected_menu_item_;
    sf::RenderWindow* window_;
    sf::RenderTexture buttons_[NUMBER_OF_MENU_ITEMS];
};

