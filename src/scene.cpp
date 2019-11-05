#include <iostream>
#include <vector>
#include "scene.hpp"
#include "player.hpp"


/* Contructor. */
Scene::Scene() {
    

}
 /* Destructor */
Scene::~Scene() {
    
}

/* Run and setup singleplayer scene. */
void Scene::Init() {
    //Load map from file
    //Place players on map


    Player* player = new Player(sf::Vector2f(0.0f, 0.0f));
    // players_.push_back(player);
    player->Loop();
    
    delete player;

    End();

}

/* Delete objects from scene and close */
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
