#pragma once

#include <iostream>
#include <vector>
#include "maploader.hpp"

class GameObject;

/* Allows the usege of global variable main_window and its functions */
extern sf::RenderWindow* main_window;
extern int g_fps;

class Scene {
public:
    /* Constructor */
    Scene();

    /* Copy constructor */
    Scene(const Scene&);

    /* Copy assignment operator */
    Scene& operator=(const Scene&);

    /* Destructor */
    ~Scene();

    /* Run and setup singleplayer scene */
    void Init();

    /* Game loop */
    void Loop();

    /* Update game logic (bullets etc.) */
    void Update();

    /* Render the game and update graphics */
    void Render();

    std::vector<GameObject*> GetObjects() { return objects_; }

private:
    Map map_;
    sf::Texture background_;
    Player* player_;
    std::vector<GameObject*> objects_;
    std::vector<GameObject*> enemies_;
    std::vector<Projectile*> projectiles_;
};
