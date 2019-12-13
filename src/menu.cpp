#include "menu.hpp"

/* Construct and load default main menu */
Menu::Menu() {
    if (!main_menu_texture_.loadFromFile("src/Textures/MenuButtons/mainmenu.png")) {
        std::cout << "ERROR loading main menu button texture!" << std::endl;
    }
    if (!logo_texture_.loadFromFile("src/Textures/MenuButtons/logo.png")) {
        std::cout << "ERROR loading main menu button texture!" << std::endl;
    }
    if (!main_menu_background_.loadFromFile("src/Textures/MenuButtons/background.png")) {
        std::cout << "ERROR loading main menu background texture!" << std::endl;
    }
    if (!font_.loadFromFile("src/Textures/MenuButtons/MenuFont.ttf")) {
        std::cout << "ERROR loading main menu button font!" << std::endl;
    }
    if (!music_.openFromFile("src/Audio/Music/music_menu.ogg")) {
        std::cout << "ERROR loading main menu music!" << std::endl;
    }
    if (!buffer_.loadFromFile("src/Audio/Sound/sound_button.ogg")) {
        std::cout << "ERROR loading main menu button sound!" << std::endl;
    }
    button_.setBuffer(buffer_);
    menu_status = 0;
    x_ = 0;
    LoadMainMenu();
    music_.play();
    music_.setLoop(true);
    Draw();
}

/* Draws all the sprites in the menu items vector and handle menu background animation */
void Menu::Draw() {
    sf::Sprite background;
    background.setTexture(main_menu_background_);

    if (x_ > 3200) {
        x_ = 0;
    }
    else {
        x_ += 0.3;
    }
    background.setTextureRect(sf::Rect(int(x_), 0, 3200, 1200));

    main_window->draw(background);
    for (sf::Sprite it : menu_items_) {
        main_window->draw(it);
    }
    for (sf::Text it : menu_text_items_) {
        main_window->draw(it);
    }
    if (menu_status == 2) {
        std::string inputstr = playername_.getString().toAnsiString();
        sf::Text userinput;
        userinput.setFont(font_);
        userinput.setCharacterSize(50);
        userinput.setPosition(main_window->getSize().x / 3.4 , main_window->getSize().y / 3);
        userinput.setString(inputstr);
        main_window->draw(userinput);
    }
}

/* Initialize the window and loads main menu by default. Handle button hover and button clicks.
   menu_status indicates the screen to be loaded. 0 = Main menu, 1 = Settings menu... */
void Menu::Init() {
    main_window->setFramerateLimit(g_fps*6);
    while (main_window->isOpen()) {
        main_window->clear();
        sf::Event event;
        main_window->pollEvent(event);

        // Main menu
        if (menu_status == 0) {
            if (event.type == sf::Event::Closed) {
                main_window->close();
            }            sf::Text text;

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
                    if (sound_on) {
                        button_.play();
                    }
                    LoadNameMenu();
                }

                else if (menu_items_[1].getGlobalBounds().contains(mouse_pos)) {
                    if (sound_on) {
                        button_.play();
                    }
                    LoadSettingsMenu();
                }

                else if (menu_items_[2].getGlobalBounds().contains(mouse_pos)) {
                    if (sound_on) {
                        button_.play();
                    }
                    main_window->close();
                }


            }
        }

        // Settings menu
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
                    if (sound_on) {
                        button_.play();
                    }
                    LoadMainMenu();
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
                            button_.play();
                            sound_on = true;
                        }
                    }

                    if (music_on) {
                        if (menu_items_[2].getGlobalBounds().contains(mouse_pos)) {
                            menu_items_[2].setTextureRect(sf::Rect(0, 600, 250, 120));
                            if (sound_on) {
                                button_.play();
                            }
                            music_.stop();
                            music_on = false;
                        }
                    }

                    else {
                        if (menu_items_[2].getGlobalBounds().contains(mouse_pos)) {
                            menu_items_[2].setTextureRect(sf::Rect(0, 480, 250, 120));
                            if (sound_on) {
                                button_.play();
                            }
                            music_.play();
                            music_.setLoop(true);
                            music_on = true;
                        }
                    }
                }
            }
        }

        // Name menu
        else if (menu_status == 2) {
            sf::String name;

            if (event.type == sf::Event::Closed) {
                main_window->close();
            }

            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == 8 && playername_.getString().getSize() > 0) {
                    sf::String temporary = playername_.getString();
                    temporary.erase(temporary.getSize() - 1, temporary.getSize());
                    playername_.setString(temporary);
                }

                else if (event.text.unicode < 127 && event.text.unicode > 31 && playername_.getString().getSize() < 15) {
                    name += event.text.unicode;
                    playername_.setString(playername_.getString() + name);
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                if (sound_on) {
                    button_.play();
                }
                LoadGameMode();
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
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Mouse cursor;
                sf::Vector2i mouse_position = cursor.getPosition(*main_window);
                sf::Vector2f mouse_pos(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y));

                if (menu_items_[0].getGlobalBounds().contains(mouse_pos)) {
                    if (sound_on) {
                        button_.play();
                    }
                    LoadMainMenu();
                }
            }
        }

        // Play menu
        else if (menu_status == 3) {
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
                    if (sound_on) {
                        button_.play();
                    }
                    LoadNameMenu();
                }

                else if (menu_items_[1].getGlobalBounds().contains(mouse_pos)) {
                    if (sound_on) {
                        button_.play();
                    }
                    LoadCampaign();
                }

                else if (menu_items_[2].getGlobalBounds().contains(mouse_pos)) {
                    if (sound_on) {
                        button_.play();
                    }
                    LoadSurvival();
                }
            }
        }

        // Campaign menu
        else if (menu_status == 4) {
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

                if (menu_items_[3].getGlobalBounds().contains(mouse_pos)) {
                    menu_items_[3].setColor(sf::Color(sf::Color::Red));
                }
                else {
                    menu_items_[3].setColor(sf::Color(sf::Color::White));
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Mouse cursor;
                sf::Vector2i mouse_position = cursor.getPosition(*main_window);
                sf::Vector2f mouse_pos(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y));

                if (menu_items_[0].getGlobalBounds().contains(mouse_pos)) {
                    if (sound_on) {
                        button_.play();
                    }
                    LoadGameMode();
                }

                else if (menu_items_[1].getGlobalBounds().contains(mouse_pos)) {
                    if (sound_on) {
                        button_.play();
                    }
                    ClearMenuItems();
                    music_.stop();
                    Scene scene = Scene("src/Maps/campaign_map1.txt", playername_);
                    scene.Init();

                    if (music_on) {
                        music_.play();
                        music_.setLoop(true);
                    }
                    main_window->setView(sf::View());
                    main_window->setFramerateLimit(g_fps*6);
                    LoadMainMenu();
                }

                else if (menu_items_[2].getGlobalBounds().contains(mouse_pos)) {
                    if (sound_on) {
                        button_.play();
                    }
                    ClearMenuItems();
                    music_.stop();
                    Scene scene = Scene("src/Maps/campaign_map2.txt", playername_);
                    scene.Init();
                    if (music_on) {
                        music_.play();
                        music_.setLoop(true);
                    }
                    main_window->setView(sf::View());
                    main_window->setFramerateLimit(g_fps*6);
                    LoadMainMenu();
                }

                else if (menu_items_[3].getGlobalBounds().contains(mouse_pos)) {
                    if (sound_on) {
                        button_.play();
                    }
                    ClearMenuItems();
                    music_.stop();
                    Scene scene = Scene("src/Maps/campaign_map3.txt", playername_);
                    scene.Init();
                    if (music_on) {
                        music_.play();
                        music_.setLoop(true);
                    }
                    main_window->setView(sf::View());
                    main_window->setFramerateLimit(g_fps*6);
                    LoadMainMenu();
                }
            }
        }

        // Survival menu
        else if (menu_status == 5) {
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

                if (menu_items_[3].getGlobalBounds().contains(mouse_pos)) {
                    menu_items_[3].setColor(sf::Color(sf::Color::Red));
                }
                else {
                    menu_items_[3].setColor(sf::Color(sf::Color::White));
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Mouse cursor;
                sf::Vector2i mouse_position = cursor.getPosition(*main_window);
                sf::Vector2f mouse_pos(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y));

                if (menu_items_[0].getGlobalBounds().contains(mouse_pos)) {
                    if (sound_on) {
                        button_.play();
                    }
                    LoadGameMode();
                }

                else if (menu_items_[1].getGlobalBounds().contains(mouse_pos)) {
                    if (sound_on) {
                        button_.play();
                    }
                    ClearMenuItems();
                    music_.stop();
                    Scene scene = Scene("src/Maps/survival_map1.txt", playername_);
                    scene.Init();
                    if (music_on) {
                        music_.play();
                        music_.setLoop(true);
                    }
                    main_window->setView(sf::View());
                    main_window->setFramerateLimit(g_fps*6);
                    LoadMainMenu();
                }

                else if (menu_items_[2].getGlobalBounds().contains(mouse_pos)) {
                    if (sound_on) {
                        button_.play();
                    }
                    ClearMenuItems();
                    music_.stop();
                    Scene scene = Scene("src/Maps/survival_map2.txt", playername_);
                    scene.Init();
                    if (music_on) {
                        music_.play();
                        music_.setLoop(true);
                    }
                    main_window->setView(sf::View());
                    main_window->setFramerateLimit(g_fps*6);
                    LoadMainMenu();
                }

                else if (menu_items_[3].getGlobalBounds().contains(mouse_pos)) {
                    if (sound_on) {
                        button_.play();
                    }
                    ClearMenuItems();
                    music_.stop();
                    Scene scene = Scene("src/Maps/survival_map3.txt", playername_);
                    scene.Init();
                    if (music_on) {
                        music_.play();
                        music_.setLoop(true);
                    }
                    main_window->setView(sf::View());
                    main_window->setFramerateLimit(g_fps*6);
                    LoadMainMenu();
                }
            }
        }
        Draw();
        main_window->display();
    }
}

/* Add main menu sprites to the menuitems vector */
void Menu::LoadMainMenu() {
    ClearMenuItems();
    menu_status = 0;
    sf::Vector2u window_size = main_window->getSize();
    sf::Sprite play;
    sf::Sprite settings;
    sf::Sprite exit;
    sf::Sprite logo;

    logo.setTexture(logo_texture_);
    logo.setTextureRect(sf::Rect(0, 0, 183, 43));
    logo.setScale(sf::Vector2f(2.5, 2.5));
    logo.setPosition(sf::Vector2f(window_size.x / 3.5 , window_size.y / 9));

    play.setTexture(main_menu_texture_);
    play.setTextureRect(sf::Rect(0, 0, 250, 120));
    play.setPosition(sf::Vector2f(window_size.x / 2.6 , window_size.y / 4));

    settings.setTexture(main_menu_texture_);
    settings.setTextureRect(sf::Rect(0, 120, 250, 120));
    settings.setPosition(sf::Vector2f(window_size.x / 2.6 , window_size.y / 2.4));

    exit.setTexture(main_menu_texture_);
    exit.setTextureRect(sf::Rect(0, 240, 250, 120));
    exit.setPosition(sf::Vector2f(window_size.x / 2.6 , window_size.y / 1.7));

    menu_items_.push_back(play);
    menu_items_.push_back(settings);
    menu_items_.push_back(exit);
    menu_items_.push_back(logo);
}

/* Add settings menu sprites to the menuitems vector */
void Menu::LoadSettingsMenu() {
    ClearMenuItems();
    menu_status = 1;
    sf::Vector2u window_size = main_window->getSize();
    sf::Sprite music;
    sf::Sprite sound;
    sf::Sprite back;

    back.setTexture(main_menu_texture_);
    back.setTextureRect(sf::Rect(0, 360, 250, 120));
    back.setPosition(sf::Vector2f(window_size.x / 2.6 , window_size.y / 1.7));

    music.setTexture(main_menu_texture_);
    music.setPosition(sf::Vector2f(window_size.x / 2.6 , window_size.y / 4));

    if (music_on) {
        music.setTextureRect(sf::Rect(0, 480, 250, 120));
    }
    else {
        music.setTextureRect(sf::Rect(0, 600, 250, 120));
    }

    sound.setTexture(main_menu_texture_);
    sound.setPosition(sf::Vector2f(window_size.x / 2.6 , window_size.y / 2.4));

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

/* Add name menu sprites to the menuitems vector */
void Menu::LoadNameMenu() {
    ClearMenuItems();
    menu_status = 2;
    sf::Vector2u window_size = main_window->getSize();
    sf::Sprite back;
    sf::Text enter_name;

    std::string str = "Enter player name (max 15 characters)";
    enter_name.setFont(font_);
    enter_name.setString(str);
    enter_name.setPosition(sf::Vector2f(window_size.x / 4.3 , window_size.y / 4));

    back.setTexture(main_menu_texture_);
    back.setTextureRect(sf::Rect(0, 360, 250, 120));
    back.setPosition(sf::Vector2f(window_size.x / 2.6 , window_size.y / 1.7));

    menu_items_.push_back(back);
    menu_text_items_.push_back(enter_name);
}

/* Add play menu sprites to the menuitems vector */
void Menu::LoadGameMode() {
    ClearMenuItems();
    menu_status = 3;
    sf::Vector2u window_size = main_window->getSize();
    sf::Sprite back;
    sf::Sprite host;
    sf::Sprite join;
    sf::Text help;

    std::string str = "Select a game mode";
    help.setFont(font_);
    help.setString(str);
    help.setPosition(sf::Vector2f(window_size.x / 2.8 , window_size.y / 4));

    back.setTexture(main_menu_texture_);
    back.setTextureRect(sf::Rect(0, 360, 250, 120));
    back.setPosition(sf::Vector2f(window_size.x / 2.6 , window_size.y / 1.7));

    host.setTexture(main_menu_texture_);
    host.setTextureRect(sf::Rect(0, 960, 250, 120));
    host.setPosition(sf::Vector2f(window_size.x / 5 , window_size.y / 3));

    join.setTexture(main_menu_texture_);
    join.setTextureRect(sf::Rect(0, 1080, 250, 120));
    join.setPosition(sf::Vector2f(window_size.x / 1.75 , window_size.y / 3));

    menu_items_.push_back(back);
    menu_items_.push_back(host);
    menu_items_.push_back(join);
    menu_text_items_.push_back(help);
}

/* Add campaign menu sprites to the menuitems vector */
void Menu::LoadCampaign() {
    ClearMenuItems();
    menu_status = 4;
    sf::Vector2u window_size = main_window->getSize();
    sf::Sprite back;
    sf::Sprite level1;
    sf::Sprite level2;
    sf::Sprite level3;

    back.setTexture(main_menu_texture_);
    back.setTextureRect(sf::Rect(0, 360, 250, 120));
    back.setPosition(sf::Vector2f(window_size.x / 2.6 , window_size.y / 1.7));

    level1.setTexture(main_menu_texture_);
    level1.setTextureRect(sf::Rect(0, 1200, 250, 120));
    level1.setPosition(sf::Vector2f(window_size.x / 2.6 , window_size.y / 7.9));

    level2.setTexture(main_menu_texture_);
    level2.setTextureRect(sf::Rect(0, 1320, 250, 120));
    level2.setPosition(sf::Vector2f(window_size.x / 2.6 , window_size.y / 3.55));

    level3.setTexture(main_menu_texture_);
    level3.setTextureRect(sf::Rect(0, 1440, 250, 120));
    level3.setPosition(sf::Vector2f(window_size.x / 2.6 , window_size.y / 2.3));

    menu_items_.push_back(back);
    menu_items_.push_back(level1);
    menu_items_.push_back(level2);
    menu_items_.push_back(level3);
}

/* Add survival menu sprites to the menuitems vector */
void Menu::LoadSurvival() {
    ClearMenuItems();
    menu_status = 5;
    sf::Vector2u window_size = main_window->getSize();
    sf::Sprite back;
    sf::Sprite level1;
    sf::Sprite level2;
    sf::Sprite level3;

    back.setTexture(main_menu_texture_);
    back.setTextureRect(sf::Rect(0, 360, 250, 120));
    back.setPosition(sf::Vector2f(window_size.x / 2.6 , window_size.y / 1.7));

    level1.setTexture(main_menu_texture_);
    level1.setTextureRect(sf::Rect(0, 1200, 250, 120));
    level1.setPosition(sf::Vector2f(window_size.x / 2.6 , window_size.y / 7.9));

    level2.setTexture(main_menu_texture_);
    level2.setTextureRect(sf::Rect(0, 1320, 250, 120));
    level2.setPosition(sf::Vector2f(window_size.x / 2.6 , window_size.y / 3.55));

    level3.setTexture(main_menu_texture_);
    level3.setTextureRect(sf::Rect(0, 1440, 250, 120));
    level3.setPosition(sf::Vector2f(window_size.x / 2.6 , window_size.y / 2.3));

    menu_items_.push_back(back);
    menu_items_.push_back(level1);
    menu_items_.push_back(level2);
    menu_items_.push_back(level3);
}

/* Clear menu items vector of sprites */
void Menu::ClearMenuItems() {
    menu_items_.clear();
    menu_text_items_.clear();
}
