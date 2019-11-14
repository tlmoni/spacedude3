#include "menu.hpp"

/* Construct and load default main menu. */
Menu::Menu() {
    main_menu_texture_.loadFromFile("src/Textures/MenuButtons/mainmenu.png");
    main_menu_background_.loadFromFile("src/Textures/MenuButtons/menu_background.png");
    menu_status = 0;
    Load_MainMenu();
    Draw();
}

/* Draws all the sprites in the menu items vector. */
void Menu::Draw() {
    sf::Sprite background;
    background.setTexture(main_menu_background_);
    main_window->draw(background);
    for (auto it = menu_items_.begin(); it != menu_items_.end(); it++) {
        main_window->draw(*it);
    }
}

/* Initialize the window and loads main menu by default. menu_status indicates
    the screen to be loaded. 0 = Main menu, 1 = Settings menu... */
void Menu::Init() {
    while (main_window->isOpen()) {
        main_window->clear();
        sf::Event event;
        main_window->pollEvent(event);

        if (menu_status == 0) {
            if (event.type == sf::Event::Closed) {
                main_window->close();
            }

            if (event.type == sf::Event::MouseMoved) {
                sf::Mouse cursor;
                sf::Vector2i mouse_position = cursor.getPosition(*main_window);
                sf::Vector2f mouse_pos(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y));

                if (menu_items_[0].getGlobalBounds().contains(mouse_pos)) {
                    menu_items_[0].setColor(sf::Color(sf::Color::Red));
                }
                else {
                    menu_items_[0].setColor(sf::Color(sf::Color::White));
                }

                if (menu_items_[1].getGlobalBounds().contains(mouse_pos)) {
                    menu_items_[1].setColor(sf::Color(sf::Color::Red));
                }
                else {
                    menu_items_[1].setColor(sf::Color(sf::Color::White));
                }

                if (menu_items_[2].getGlobalBounds().contains(mouse_pos)) {
                    menu_items_[2].setColor(sf::Color(sf::Color::Red));
                }
                else {
                    menu_items_[2].setColor(sf::Color(sf::Color::White));
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Mouse cursor;
                sf::Vector2i mouse_position = cursor.getPosition(*main_window);
                sf::Vector2f mouse_pos(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y));

                if (menu_items_[0].getGlobalBounds().contains(mouse_pos)) {
                    Scene* scene = new Scene();
                    scene->Init();
                    delete scene;
                }

                if (menu_items_[1].getGlobalBounds().contains(mouse_pos)) {
                    Load_SettingsMenu();
                }

                if (menu_items_[2].getGlobalBounds().contains(mouse_pos)) {
                    main_window->close();
                }


            }
        }

        else if (menu_status == 1) {
            if (event.type == sf::Event::Closed) {
                main_window->close();
            }

            if (event.type == sf::Event::MouseMoved) {
                sf::Mouse cursor;
                sf::Vector2i mouse_position = cursor.getPosition(*main_window);
                sf::Vector2f mouse_pos(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y));

                if (menu_items_[0].getGlobalBounds().contains(mouse_pos)) {
                    menu_items_[0].setColor(sf::Color(sf::Color::Red));
                }
                else {
                    menu_items_[0].setColor(sf::Color(sf::Color::White));
                }

                if (menu_items_[1].getGlobalBounds().contains(mouse_pos)) {
                    menu_items_[1].setColor(sf::Color(sf::Color::Red));
                }
                else {
                    menu_items_[1].setColor(sf::Color(sf::Color::White));
                }

                if (menu_items_[2].getGlobalBounds().contains(mouse_pos)) {
                    menu_items_[2].setColor(sf::Color(sf::Color::Red));
                }
                else {
                    menu_items_[2].setColor(sf::Color(sf::Color::White));
                }

            }

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Mouse cursor;
                sf::Vector2i mouse_position = cursor.getPosition(*main_window);
                sf::Vector2f mouse_pos(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y));

                if (menu_items_[0].getGlobalBounds().contains(mouse_pos)) {
                    Load_MainMenu();
                }

                else {
                    if (sound_on) {
                        if (menu_items_[1].getGlobalBounds().contains(mouse_pos)) {
                            menu_items_[1].setTextureRect(sf::Rect(0, 840, 250, 120));
                            sound_on = false;
                        }
                    }

                    else {
                        if (menu_items_[1].getGlobalBounds().contains(mouse_pos)) {
                            menu_items_[1].setTextureRect(sf::Rect(0, 720, 250, 120));
                            sound_on = true;
                        }
                    }

                    if (music_on) {
                        if (menu_items_[2].getGlobalBounds().contains(mouse_pos)) {
                            menu_items_[2].setTextureRect(sf::Rect(0, 600, 250, 120));
                            music_on = false;
                        }
                    }

                    else {
                        if (menu_items_[2].getGlobalBounds().contains(mouse_pos)) {
                            menu_items_[2].setTextureRect(sf::Rect(0, 480, 250, 120));
                            music_on = true;
                        }
                    }
                }
            }
        }
        Draw();
        main_window->display();
    }
}

/* Add main menu sprites to the menuitems vector */
void Menu::Load_MainMenu() {
    Clear_MenuItems();
    menu_status = 0;
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
    Clear_MenuItems();
    menu_status = 1;
    sf::Vector2u window_size = main_window->getSize();
    sf::Sprite music;
    sf::Sprite sound;
    sf::Sprite back;

    back.setTexture(main_menu_texture_);
    back.setTextureRect(sf::Rect(0, 360, 250, 120));
    back.setPosition(sf::Vector2f(window_size.x / 2.4 , window_size.y / 1.7));

    music.setTexture(main_menu_texture_);
    music.setPosition(sf::Vector2f(window_size.x / 2.4 , window_size.y / 4));

    if (music_on) {
        music.setTextureRect(sf::Rect(0, 480, 250, 120));
    }
    else {
        music.setTextureRect(sf::Rect(0, 600, 250, 120));
    }

    sound.setTexture(main_menu_texture_);
    sound.setPosition(sf::Vector2f(window_size.x / 2.4 , window_size.y / 2.4));

    if (sound_on) {
        sound.setTextureRect(sf::Rect(0, 720, 250, 120));
    }
    else {
        sound.setTextureRect(sf::Rect(0, 840, 250, 120));
    }

    menu_items_.push_back(back);
    menu_items_.push_back(sound);
    menu_items_.push_back(music);
}

/* Add play menu sprites to the menuitems vector */
void Menu::Load_PlayMenu() {

}

/* Clear menu items vector of sprites */
void Menu::Clear_MenuItems() {
    menu_items_.clear();
}