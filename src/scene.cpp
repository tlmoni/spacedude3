#include "scene.hpp"

/* Contructor */
Scene::Scene(std::string map, sf::Text playername) {
    if(!cursor_.loadFromFile("src/Textures/crosshair31.png")) {
        std::cout << "ERROR while reading cursor texture file" << std::endl;
    }
    map_ = MapLoader::LoadMap(map);
    cursor_sprite_.setTexture(cursor_);
    cursor_sprite_.setOrigin(sf::Vector2f(13.f,13.f));
    playername_ = playername;
    if (!font_.loadFromFile("src/Textures/MenuButtons/MenuFont.ttf")) {
        std::cout << "ERROR while loading font" << std::endl;
    }
    killcount_ = 0;
    kills_.setFont(font_);
    kills_.setCharacterSize(30);
    playername_.setFont(font_);
    playername_.setCharacterSize(12);
}

/* Copy constructor */
Scene::Scene(const Scene& scene) {
    *this = scene;
}

/* Copy assignment operator */
Scene& Scene::operator=(const Scene& scene) {
    map_ = scene.map_;
    player_ = scene.player_;
    projectiles_ = scene.projectiles_;

    return *this;
}

/* Destructor */
Scene::~Scene() {
    main_window->clear();
    for (GameObject* obj : map_.objects) {
        delete obj;
    }
    for (Projectile* p : projectiles_) {
        delete p;
    }
    delete map_.goal;
    delete player_;
}

/* Run and setup singleplayer scene */
void Scene::Init() {
    // Init cursor
    main_window->setMouseCursorVisible(false);

    // Init map
    if (music_on) {
        if (!music_.openFromFile("src/Audio/Music/music_game.ogg")) {
            std::cout << "ERROR loading game music" << std::endl;
        }
        music_.setVolume(60);
        music_.setLoop(true);
        music_.play();
    }

    SpaceDude* spacedude = new SpaceDude();
    player_ = new Player(spacedude, map_.player_location);

    main_window->setFramerateLimit(g_fps);
    Render();
    Loop();
}

/* Handle player movement and events, update these to the scene */
void Scene::Loop() {
    while (main_window->isOpen() && !end_) {
        sf::Event event;

        main_window->pollEvent(event);
        switch (event.type) {
            case sf::Event::Closed:
                main_window->close();
                break;
            default:
                break;
        }
        if (main_window->hasFocus()) {
            Update();
            Render();

            // If Esc key is pressed, return to menu
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
                main_window->setMouseCursorVisible(true);
                while (main_window->pollEvent(event)) { } // Clear keypress/mouse click events
                return;
            }

            // Check if the player has rached the goal
            if (player_->CollidesWith(map_.goal)) {
                music_.stop();
                DisplayVictoryScreen();
                return;
            }
        }

    }

    DisplayDeathScreen();
}

/* Update game logic (bullets etc.) */
void Scene::Update() {
    if (!player_->dead_) {
        // Handle player action
        AddProjectiles(player_->Action(GetObjects()));

        // Handle enemy action
        for (auto e : map_.enemies) {
            if (!e->dead_) {
                AddProjectiles(e->Action(GetObjects(), player_->GetPosition()));
            }
        }

        // Handle projectiles
        for (auto p = projectiles_.begin(); p != projectiles_.end(); p++) {
            if ((*p)->GetVelocity().Length() == 0) {
                projectiles_.erase(p);
                p--;
            }
            else {
                bool collided1 = false;
                bool collided2 = false;
                std::vector<GameObject*> player;
                player.push_back(player_);
                collided1 = (*p)->CheckCollisions(map_.objects);
                collided2 = (*p)->CheckCollisions(player);
                if (collided1 || collided2) {
                    projectiles_.erase(p);
                    p--;
                }
                else {
                    (*p)->SetPosition((*p)->GetPosition() + (*p)->GetVelocity());
                    (*p)->Decelerate((*p)->GetAcceleration());
                }
            }
        }

        // Handle objects
        for (auto o = map_.objects.begin(); o != map_.objects.end(); o++) {
            (*o)->UpdateHP();

            // Objects
            if ((*o)->GetType() == DESTRUCTABLE_WALL) {
                if ((*o)->dead_) {
                    if ((*o)->shootable_) {
                        if (sound_on) {
                            (*o)->DeathSound();
                        }
                        (*o)->shootable_ = false;
                    }
                    (*o)->GetTexture()->loadFromFile("src/Textures/broken_crate.png");
                }
            }

            // Enemies
            if ((*o)->GetType() == ENEMY) {
                if ((*o)->GetHitPoints() <= 0 && !(*o)->dead_) {
                    if (sound_on) {
                        (*o)->DeathSound();
                    }
                    (*o)->collidable_ = false;
                    (*o)->shootable_ = false;
                    (*o)->dead_ = true;
                    killcount_++;
                    (*o)->deadtimer_.restart();
                    (*o)->GetTexture()->loadFromFile("src/Textures/dead_zombie.png");
                    map_.enemies_left--;
                }
                else if ((*o)->deadtimer_.getElapsedTime().asMilliseconds() > 20000 && (*o)->dead_) {
                    map_.objects.erase(o);
                    o--;
                }
            }
        }

        // Make the goal portal accessible
        if (map_.enemies_left == 0) {
            if (!map_.goal->collidable_) {
                if (!map_.portal_buffer.loadFromFile("src/Audio/Sound/sound_portal.ogg")) {
                    std::cout << "ERROR while loading portal sound effect" << std::endl;
                }
                map_.portal_sound.setBuffer(map_.portal_buffer);
                map_.portal_sound.play();
                map_.goal->collidable_ = true;
            }
            map_.goal->Rotate(-2);
        }
    }
    else if (!end_) {
        if (sound_on) {
            player_->PlayDeathSound();
        }
        music_.stop();
        end_ = true;
    }

    // Move cursor
    cursor_sprite_.setPosition(main_window->getView().getCenter() - sf::Vector2f(500,500) + static_cast<sf::Vector2f>(sf::Mouse::getPosition(*main_window)));
}

/* Render the game and update graphics */
void Scene::Render() {
    main_window->clear();

    for (auto b : map_.background) {
        main_window->draw(*b);
    }

    for(GameObject* o : map_.objects) {
        main_window->draw(o->GetSprite());
        if (!o->dead_ && o->GetType() != DESTRUCTABLE_WALL && o->GetType() != WALL) {
            main_window->draw(o->GetHPBackground());
            main_window->draw(o->GetHPBar());
        }
    }

    if (projectiles_.empty() == false) {
        for(Projectile* p : projectiles_) {
            main_window->draw(p->GetSprite());
        }
    }

    if (map_.enemies_left == 0) {
        main_window->draw(map_.goal->GetSprite());
    }

    player_->UpdateHP();
    player_->Draw();
    playername_.setPosition(player_->GetPosition().x - (3.5 * (playername_.getString().getSize())), player_->GetPosition().y - 60);
    main_window->draw(playername_);
    kills_.setString("Kills: " + std::to_string(killcount_));
    kills_.setPosition(player_->GetPosition().x - 500, player_->GetPosition().y - 500);
    main_window->draw(kills_);

    main_window->draw(cursor_sprite_);

    main_window->display();
}

void Scene::AddProjectiles(std::vector<Projectile*> projectiles) {
    if (projectiles.empty() == false) {
        for (Projectile* p : projectiles) {
            projectiles_.push_back(p);
        }
    }
}

void Scene::DisplayVictoryScreen() {
    sf::Font font;
    if (!font.loadFromFile("src/Textures/MenuButtons/MenuFont.ttf")) {
        std::cout << "ERROR loading font" << std::endl;
    }

    sf::Text game_win;
    std::string str = "VICTORY!";
    game_win.setFont(font);
    game_win.setString(str);
    game_win.setFillColor(sf::Color(30,150,30));
    game_win.setScale(sf::Vector2f(1.3, 1.3));
    game_win.setPosition(main_window->getView().getCenter() - sf::Vector2f(10 * (game_win.getString().getSize()), 200));

    sf::Text game_win2;
    std::string str2 = "Press ESC to return to menu";
    game_win2.setFont(font);
    game_win2.setString(str2);
    game_win2.setFillColor(sf::Color(30,150,30));
    game_win2.setScale(sf::Vector2f(1.3, 1.3));
    game_win2.setPosition(main_window->getView().getCenter() - sf::Vector2f(10 * (game_win2.getString().getSize()), 160));

    sf::Sound victory_sound;
    sf::SoundBuffer victory_buffer;
    if (!victory_buffer.loadFromFile("src/Audio/Sound/sound_victory.ogg")) {
        std::cout << "ERROR while loading victory sound effect" << std::endl;
    }
    victory_sound.setBuffer(victory_buffer);
    victory_sound.play();

    Update();
    Render();

    while (main_window->isOpen()) {
        sf::Event event;
        switch (event.type) {
            case sf::Event::Closed:
                main_window->close();
                break;
            default:
                break;
        }

        // If Esc key is pressed, return to menu
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            main_window->setMouseCursorVisible(true);
            while (main_window->pollEvent(event)) { } // Clear keypress/mouse click events
            player_->StopDeathSound();
            return;
        }

        main_window->draw(game_win);
        main_window->draw(game_win2);
        main_window->display();
    }
}

void Scene::DisplayDeathScreen() {
    sf::Font font;
    if (!font.loadFromFile("src/Textures/MenuButtons/MenuFont.ttf")) {
        std::cout << "ERROR loading font" << std::endl;
    }
    sf::Text game_end;
    std::string str = "YOU DIED!";
    game_end.setFont(font);
    game_end.setString(str);
    game_end.setFillColor(sf::Color::Red);
    game_end.setScale(sf::Vector2f(1.3, 1.3));
    game_end.setPosition(main_window->getView().getCenter() - sf::Vector2f(10 * (game_end.getString().getSize()), 200));

    sf::Text game_end2;
    std::string str2 = "Press ESC to return to menu";
    game_end2.setFont(font);
    game_end2.setString(str2);
    game_end2.setFillColor(sf::Color::Red);
    game_end2.setScale(sf::Vector2f(1.3, 1.3));
    game_end2.setPosition(main_window->getView().getCenter() - sf::Vector2f(10 * (game_end2.getString().getSize()), 160));

    player_->SetSprite("src/Textures/deadspacedude.png");
    Update();
    Render();

    while (main_window->isOpen()) {
        sf::Event event;
        switch (event.type) {
            case sf::Event::Closed:
                main_window->close();
                break;
            default:
                break;
        }

        // If Esc key is pressed, return to menu
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            main_window->setMouseCursorVisible(true);
            while (main_window->pollEvent(event)) { } // Clear keypress/mouse click events
            player_->StopDeathSound();
            return;
        }

        main_window->draw(game_end);
        main_window->draw(game_end2);
        main_window->display();
    }
}

