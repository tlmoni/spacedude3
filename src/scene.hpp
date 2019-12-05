#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameObjects/wall.hpp"
#include "player.hpp"
#include "GameObjects/projectile.hpp"

/* Forward declaration of Player needed here */
class Player;

/* Allows the usege of global variable main_window and its functions */
extern sf::RenderWindow* main_window;
extern int g_fps;

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

    /* Game loop */
    void Loop();

    /* Update game logic (bullets etc.) */
    void Update();

    /* Render the game and update graphics */
    void Render();

    std::vector<GameObject*> GetObjects() { return objects_; }

private:
    std::vector<GameObject*> objects_;
    Player* player_;
};
