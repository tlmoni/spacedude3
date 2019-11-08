#pragma once

#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "constants.hpp"
#include "scene.hpp"

extern sf::RenderWindow* main_window;

/* Class description */
class Menu {
public:
    /* Constructor */
    Menu();

    /* Default destructor */
    ~Menu() = default;

    /* Method description */
    void Draw();

    /* Initializes the menu loop that opens the window */
    void Init();

    /* Add main menu sprites to the menuitems list */
    void Load_MainMenu();

    /* Add settings menu sprites to the menuitems list */
    void Load_SettingsMenu();

    /* Add play menu sprites to the menuitems list */
    void Load_PlayMenu();

    /* Clear window and menu items list of sprites */
    void Clear_MenuItems();

private:
    std::vector<sf::Sprite> menu_items_; // Vector that holds all the menu sprites
    sf::Texture main_menu_texture_; // Texture for main menu buttons
    sf::Texture main_menu_background_; // Texture for menu background
    int menu_status; // Indicates which menu scenario is to be loaded
};
