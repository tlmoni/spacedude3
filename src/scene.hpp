#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "player.hpp"

extern sf::RenderWindow* main_window;

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

    /* UNDER CONSTRUCTION: Getting map_ to other functions */

    sf::Sprite GetMap() { return map_; }

    /* UNDER CONSTRUCTION END */
private:
    // std::vector<GameObject*> objects_;
    // std::vector<Player*> players_;

    /* UNDER CONSTRUCTION: Loading a map to the scene */
    sf::Sprite map_;
    sf::Texture map_texture_;
    /* UNDER CONSTRUCTION END */
};
