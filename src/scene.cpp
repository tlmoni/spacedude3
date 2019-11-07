#include <iostream>
#include <vector>
#include "scene.hpp"
#include "player.hpp"

/* Contructor */
Scene::Scene() {

}

 /* Destructor */
Scene::~Scene() {

}

/* Run and setup singleplayer scene. */
void Scene::Init() {
    // Load map from file
    if (!map_texture_.loadFromFile("src/Textures/map.png")){
        map_texture_.loadFromFile("src/Textures/error.png");
    }
    map_.setTexture(map_texture_);
    // Place players on map

    Player* player = new Player(sf::Vector2f(0.0f, 0.0f));
    // players_.push_back(player);
    player->Loop();

    delete player;

    End();
}

/* Deletes objects on the scene and closes it */
void Scene::End() {
    /*
    for (auto p : players_) {
        delete p;
    }
    players_.clear();
    */
    main_window->clear();
}

/* Update game logic. Bullets etc. */
void Scene::Update() {

}

/* Render the game and update graphics */
void Scene::Render() {
    /*
    for (auto p : players_) {
        main_window->draw(p->GetSprite());
    }
    */

    main_window->display();

}
