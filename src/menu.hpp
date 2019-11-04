#pragma once

#include "SFML/Graphics.hpp"
#include "constants.hpp"

enum MenuButtons { PLAY, SETTINGS, EXIT };

class Menu {
public:
    Menu(float width, float height);

    ~Menu() = default;

    void Draw(sf::RenderWindow* window);

    void Move_Up();

    void Move_Down();

private:
    int selected_menu_item_;
};