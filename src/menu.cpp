#include "menu.hpp"

/* Construct and load default main menu. */
Menu::Menu() {
    main_menu_texture_.loadFromFile("src/Textures/MenuButtons/mainmenu.jpg");
    Load_MainMenu();
    Draw();
}

/* Draws all the sprites in the menu items vector. */
void Menu::Draw() {
    for (auto it = menu_items_.begin(); it != menu_items_.end(); it++) {
        main_window->draw(*it);
    }
    main_window->display();
}

/* Add main menu sprites to the menuitems vector */
void Menu::Load_MainMenu() {
    Clear_MenuItems();
    sf::Vector2u window_size = main_window->getSize();
    sf::Sprite play;
    sf::Sprite settings;
    sf::Sprite exit;
    play.setTexture(main_menu_texture_);
    play.setTextureRect(sf::Rect(0, 0, 250, 120));
    play.setPosition(sf::Vector2f(window_size.x / 2.4 , window_size.y / 4));
    settings.setTexture(main_menu_texture_);
    settings.setTextureRect(sf::Rect(0, 120, 250, 120));
    settings.setPosition(sf::Vector2f(window_size.x / 2.4 , window_size.y / 2.4));
    exit.setTexture(main_menu_texture_);
    exit.setTextureRect(sf::Rect(0, 240, 250, 120));
    exit.setPosition(sf::Vector2f(window_size.x / 2.4 , window_size.y / 1.7));
    menu_items_.push_back(play);
    menu_items_.push_back(settings);
    menu_items_.push_back(exit);
}

/* Add settings menu sprites to the menuitems vector */
void Menu::Load_SettingsMenu() {

}

/* Add play menu sprites to the menuitems vector */
void Menu::Load_PlayMenu() {

}

/* Clear menu items vector of sprites */
void Menu::Clear_MenuItems() {
    for (auto it = menu_items_.begin(); it != menu_items_.end(); it++) {
        menu_items_.erase(it);
    }
    menu_items_.clear();
}