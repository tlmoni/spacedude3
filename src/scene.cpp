#include "scene.hpp"

/* Contructor */
Scene::Scene() {
    CharacterSpurdo* spurdo = new CharacterSpurdo();
    Player* player = new Player(spurdo, sf::Vector2f(300.0f, 100.0f));
    Wall* wall1 = new Wall(PhysicsVector(300.f,400.f));
    Wall* wall2 = new Wall(PhysicsVector(0.f,400.f));
    player_ = player;

    objects_.push_back(wall1);
    objects_.push_back(wall2);
}

/* Destructor */
Scene::~Scene() {
    for(GameObject* obj : objects_) {
        delete obj;
    }
    delete player_;
}

/* Run and setup singleplayer scene */
void Scene::Init() {
    main_window->setFramerateLimit(g_fps);

    // Do initial drawing and rendering of objects
    main_window->clear();
    for(GameObject* obj : objects_) {
        main_window->draw(obj->GetSprite());
    }
    main_window->draw(player_->GetSprite());

    Render();

    Loop();

    End();
}

/* Deletes objects on the scene and closes it */
void Scene::End() {
    main_window->clear();
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
        main_window->draw(obj->GetSprite());
        main_window->draw(obj->GetHitbox());
    }
    main_window->draw(player_->GetSprite());
    main_window->draw(player_->GetHitbox());


    main_window->display();
}
