#pragma once

#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "constants.hpp"


/* Class description */
class Menu {
public:
    /* Constructor */
    Menu();

    /* Default destructor */
    ~Menu() = default;

    /* Method description */
    void Draw();

    /* Add main menu sprites to the menuitems list */
    void Load_MainMenu();

    /* Add settings menu sprites to the menuitems list */
    void Load_SettingsMenu();

    /* Add play menu sprites to the menuitems list */
    void Load_PlayMenu();

    /* Clear window and menu items list of sprites */
    void Clear_MenuItems();

private:
    std::vector<sf::Sprite>::iterator selected_menu_item_; // Description
    std::vector<sf::Sprite> menu_items_; // Description
    sf::Texture main_menu_texture_; // Texture for main menu buttons
};
