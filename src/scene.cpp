#include "scene.hpp"

/* Contructor */
Scene::Scene() { }

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

    auto objects = MapLoader::LoadMap("src/Maps/map1.txt");
    CharacterSpurdo* spurdo = new CharacterSpurdo();
    player_ = new Player(spurdo, objects.first);
    objects_ = objects.second;

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
            (*p)->SetPosition((*p)->GetPosition() + (*p)->GetVelocity());
            (*p)->Decelerate((*p)->GetSlowRate());
        }
    }
}

/* Render the game and update graphics */
void Scene::Render() {

    main_window->clear();
    for(GameObject* obj : objects_) {
        main_window->draw(obj->GetSprite());
        //main_window->draw(obj->GetHitbox());
    }
    if (projectiles_.empty() == false) {
        for(Projectile* p : projectiles_) {
            main_window->draw(p->GetSprite());
            //main_window->draw(p->GetHitbox());
        }
    }
    main_window->draw(player_->GetSprite());
    //main_window->draw(player_->GetHitbox());


    main_window->display();
}
