#include <iostream>
#include <vector>
#include "scene.hpp"

/* Contructor */
Scene::Scene() {

}

 /* Destructor */
Scene::~Scene() {

}

/* Run and setup singleplayer scene. */
void Scene::Init() {
    main_window->setFramerateLimit(fps);
    // Load map from file

    // Place players on map

    Player* player = new Player(sf::Vector2f(0.0f, 0.0f),"src/Textures/duderinosmall.png");
    // players_.push_back(player);
    player->Loop();

    delete player;

    End();
}

/* Deletes objects on the scene and closes it */
void Scene::End() {
    main_window->clear();
}

/* Update game logic. Bullets etc. */
void Scene::Update() {

}

/* Render the game and update graphics */
void Scene::Render() {
    main_window->display();
}
