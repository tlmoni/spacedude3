#include <iostream>
#include <vector>
#include "scene.hpp"
#include "eventhandler.hpp"


/* Contructor. */
Scene::Scene(sf::RenderWindow* window) {
    window_ = window;
}
 /* Destructor. */
Scene::~Scene() {
    delete window_;
}

/* Run and setup scene. */
void Scene::Init() {



    Loop();
}

/* Delete objects from scene and close. */
void Scene::End() {

    window_->clear();
}

/* Game checks events and updates from here. */
void Scene::Loop() {

    while(window_->isOpen()) {
        sf::Event event;
        window_->pollEvent(event);
        if (event_handler_.ProcessEvents(event) == CLOSED) {
            window_->close();
        }

        

    }
    
}

/* Render the game and update game state */
void Update() {
    
}

