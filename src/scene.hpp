#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "player.hpp"

extern sf::RenderWindow* main_window;
extern int fps;

class Scene {
public:
    /* Constructor */
    Scene();

    /* Destructor */
    ~Scene();

    /* Run and setup singleplayer scene */
    void Init();

    /* Deletes objects from the scene and closes it */
    void End();

    /* Update game logic. Bullets etc. */
    void Update();

    /* Render the game and update graphics */
    void Render();

private:
    // std::vector<GameObject*> objects_;
    // std::vector<Player*> players_;

};
