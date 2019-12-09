#include "scene.hpp"

/* Contructor */
Scene::Scene() {
    if(!cursor_.loadFromFile("src/Textures/cursor.png")) {
        // Error checking.
    }
    cursor_sprite_.setTexture(cursor_);
    cursor_sprite_.setOrigin(sf::Vector2f(13.f,13.f));
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
    delete player_;
}

/* Run and setup singleplayer scene */
void Scene::Init() {
    // Init cursor
    main_window->setMouseCursorVisible(false);


    // Init map
    map_ = MapLoader::LoadMap("src/Maps/map1.txt");
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
    while (main_window->isOpen()) {
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
            break;
        }
    }
}

/* Update game logic (bullets etc.) */
void Scene::Update() {
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
                (*o)->dead_ = true;
                (*o)->deadtimer_.restart();
                (*o)->GetTexture()->loadFromFile("src/Textures/dead_zombie.png");
            }
            else if ((*o)->deadtimer_.getElapsedTime().asMilliseconds() > 20000 && (*o)->dead_) {
                map_.objects.erase(o);
                o--;
            }
        }
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
            main_window->draw(p->GetHitbox());
        }
    }
    player_->UpdateHP();
    main_window->draw(player_->GetSprite());
    main_window->draw(player_->GetHPBackground());
    main_window->draw(player_->GetHPBar());
    main_window->draw(player_->GetHitbox());

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