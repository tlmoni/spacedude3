#include "scene.hpp"

/* Contructor */
Scene::Scene(std::string map, sf::Text playername) {
    if(!cursor_.loadFromFile("src/Textures/crosshair31.png")) {
        // Error checking.
    }
    map_ = MapLoader::LoadMap(map);
    cursor_sprite_.setTexture(cursor_);
    cursor_sprite_.setOrigin(sf::Vector2f(13.f,13.f));
    playername_ = playername;
    font_.loadFromFile("src/Textures/MenuButtons/MenuFont.ttf");
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
    background_ = scene.background_;
    player_ = scene.player_;
    projectiles_ = scene.projectiles_;

    return *this;
}

/* Destructor */
Scene::~Scene() {
    main_window->clear();
    for(GameObject* obj : map_.objects) {
        delete obj;
    }
    for(Projectile* p : projectiles_) {
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

    CharacterSpurdo* spurdo = new CharacterSpurdo();
    player_ = new Player(spurdo, map_.player_location);

    if (!background_.loadFromFile(map_.background_file)) {
        // Error handling
    }

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
            main_window->setMouseCursorVisible(true);
            while (main_window->pollEvent(event)) { } // Clear keypress/mouse click events
            return;
        }
    }

    sf::Font font;
    if (!font.loadFromFile("src/Textures/MenuButtons/MenuFont.ttf")) {
        std::cout << "ERROR loading font" << std::endl;
    }
    sf::Text gameend;
    std::string str = "YOU DIED! Press ESC to return to menu";
    gameend.setFont(font);
    gameend.setString(str);
    gameend.setFillColor(sf::Color::Red);
    gameend.setScale(sf::Vector2f(1.3, 1.3));
    gameend.setPosition(main_window->getView().getCenter() - sf::Vector2f(380, 200));

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

        main_window->draw(gameend);
        main_window->display();
    }
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
            // Enemies
            if ((*o)->GetType() == ENEMY) {
                if ((*o)->GetHitPoints() <= 0 && !(*o)->dead_) {
                    if (sound_on) {
                        (*o)->DeathSound();
                    }
                    (*o)->collidable_ = false;
                    (*o)->shootable_ = false;
                    (*o)->dead_ = true;
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
    }
    else {
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

    sf::Sprite background;
    background.setTexture(background_);
    background.setScale(sf::Vector2f(0.8f, 0.8f));
    background.setPosition(sf::Vector2f(-400.f, -400.f));
    main_window->draw(background);

    for(GameObject* o : map_.objects) {
        main_window->draw(o->GetSprite());
        if (!o->dead_) {
            o->UpdateHP();
            main_window->draw(o->GetHPBackground());
            main_window->draw(o->GetHPBar());
        }
        //main_window->draw(o->GetHitbox());
    }
    if (projectiles_.empty() == false) {
        for(Projectile* p : projectiles_) {
            main_window->draw(p->GetSprite());
            // main_window->draw(p->GetHitbox());
        }
    }

    // Render goal and make it accessible
    if (map_.enemies_left == 0) {
        map_.goal->collidable_ = true;
        map_.goal->SetSprite("src/Textures/portal.png");
        main_window->draw(map_.goal->GetSprite());
    }

    player_->UpdateHP();
    playername_.setPosition(player_->GetPosition().x-(3.5* (playername_.getString().getSize())), player_->GetPosition().y-60);
    main_window->draw(player_->GetSprite());
    main_window->draw(player_->GetHPBackground());
    main_window->draw(player_->GetHPBar());
    main_window->draw(playername_);
    // main_window->draw(player_->GetHitbox());

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
