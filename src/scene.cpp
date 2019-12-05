#include "scene.hpp"
#include "maploader.hpp"

/* Contructor */
Scene::Scene() { }

/* Destructor */
Scene::~Scene() {
    main_window->clear();
    for(GameObject* obj : objects_) {
        delete obj;
    }
    delete player_;
}

/* Run and setup singleplayer scene */
void Scene::Init() {

    auto objects = LoadMap("src/Maps/map1.txt");
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

        player_->Action();

        Render();
    }
}

/* Update game logic (bullets etc.) */
void Scene::Update() {

}

/* Render the game and update graphics */
void Scene::Render() {

    main_window->clear();

    for(GameObject* obj : objects_) {
        main_window->draw(*(obj->GetSprite()));
        //main_window->draw(obj->GetHitbox());
    }
    main_window->draw(*(player_->GetSprite()));

    //main_window->draw(player_->GetHitbox());


    main_window->display();
}
