#pragma once

#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "constants.hpp"
#include "scene.hpp"

extern sf::RenderWindow* main_window;

/* Menu class handles the composition of different menu scenarios. menu_items_ vector holds
   all the sprites used for different menu scenarios. When loading a different menu scenario
   the vector is cleared and a new scenario of sprites is loaded. */
class Menu {
public:
    /* Constructor */
    Menu();

    /* Default destructor */
    ~Menu() = default;

    /* Draws all the sprites in the menu items vector. */
    void Draw();

    /* Initialize the window and loads main menu by default. menu_status indicates
    the screen to be loaded. 0 = Main menu, 1 = Settings menu... */
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
    int music_on = true;
    int sound_on = true;
};
