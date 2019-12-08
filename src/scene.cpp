#include "scene.hpp"

/* Contructor */
Scene::Scene() { }

/* Copy constructor */
Scene::Scene(const Scene& scene) {
    *this = scene;
}

/* Copy assignment operator */
Scene& Scene::operator=(const Scene& scene) {
    map_ = scene.map_;
    background_ = scene.background_;
    player_ = scene.player_;
    objects_ = scene.objects_;
    enemies_ = scene.enemies_;
    projectiles_ = scene.projectiles_;

    return *this;
}

/* Destructor */
Scene::~Scene() {
    main_window->clear();
    for(GameObject* obj : objects_) {
        delete obj;
    }
    for(Projectile* p : projectiles_) {
        delete p;
    }
    delete player_;
}

/* Run and setup singleplayer scene */
void Scene::Init() {
    map_ = MapLoader::LoadMap("src/Maps/map1.txt");
    CharacterSpurdo* spurdo = new CharacterSpurdo();
    player_ = new Player(spurdo, map_.player_location);
    objects_ = map_.objects;
    enemies_ = map_.enemies;

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

        std::vector<Projectile*> projectiles = player_->Action(GetObjects());

        if (projectiles.empty() == false) {
            for (Projectile* p : projectiles) {
                projectiles_.push_back(p);
            }
        }

        Update();
        Render();
    }
}

/* Update game logic (bullets etc.) */
void Scene::Update() {
    for (auto p = projectiles_.begin(); p != projectiles_.end(); p++) {
        if ((*p)->GetVelocity().Length() == 0) {
            projectiles_.erase(p);
            p--;
        }
        else {
            (*p)->CheckCollisions(objects_);
            (*p)->CheckCollisions(enemies_);
            (*p)->SetPosition((*p)->GetPosition() + (*p)->GetVelocity());
            (*p)->Decelerate((*p)->GetSlowRate());
        }
    }
    for (auto e = enemies_.begin(); e != enemies_.end(); e++) {
        if ((*e)->GetHitPoints() <= 0 && !(*e)->dead_) {
            (*e)->dead_ = true;
            (*e)->deadtimer_.restart();
            (*e)->GetTexture()->loadFromFile("src/Textures/dead_zombie.png");
        }
        else if ((*e)->deadtimer_.getElapsedTime().asMilliseconds() > 20000 && (*e)->dead_) {
            enemies_.erase(e);
            e--;
        }
    }
}

/* Render the game and update graphics */
void Scene::Render() {
    main_window->clear();

    sf::Sprite background;
    background.setTexture(background_);
    background.setScale(sf::Vector2f(0.8f, 0.8f));
    background.setPosition(sf::Vector2f(-400.f, -400.f));
    main_window->draw(background);

    for(GameObject* obj : objects_) {
        main_window->draw(obj->GetSprite());
        //main_window->draw(obj->GetHitbox());
    }
    for(GameObject* enemy : enemies_) {
        main_window->draw(enemy->GetSprite());
        if (!enemy->dead_) {
            enemy->UpdateHP();
            main_window->draw(enemy->GetHPBackground());
            main_window->draw(enemy->GetHPBar());
        }
        //main_window->draw(obj->GetHitbox());
    }
    if (projectiles_.empty() == false) {
        for(Projectile* p : projectiles_) {
            main_window->draw(p->GetSprite());
            //main_window->draw(p->GetHitbox());
        }
    }
    main_window->draw(player_->GetSprite());
    main_window->draw(player_->GetHPBackground());
    main_window->draw(player_->GetHPBar());
    //main_window->draw(player_->GetHitbox());

    main_window->display();
}
