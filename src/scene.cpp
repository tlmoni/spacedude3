#include <iostream>
#include <vector>
#include "scene.hpp"
#include "inputhandler.hpp"


/* Contructor. */
Scene::Scene(sf::RenderWindow* window) {
    window_ = window;
}
 /* Destructor. */
Scene::~Scene() {
    delete window_;
}

/* Process events using input handler. */
void Scene::ProcessEvents(sf::Event& event) {

    switch (event.type) {
        case sf::Event::KeyPressed:
            input_.Add(event.key.code);
            break;
            
        case sf::Event::KeyReleased:
            input_.Remove(event.key.code);
            break;

        case sf::Event::Closed:
            window_->close();
            break;

        default:
            break;
    }
}


/* Run and setup scene. */
void Scene::Init() {

    GameLoop();
}

/* Delete objects from scene and close. */
void Scene::End() {


    window_->clear();
}

/* Game checks events and updates from here. */
void Scene::GameLoop() {

    while(window_->isOpen()) {
        sf::Event event;
        window_->pollEvent(event);
        ProcessEvents(event);

    }
    
}

