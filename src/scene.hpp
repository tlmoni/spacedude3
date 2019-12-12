#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "maploader.hpp"


class GameObject;

// Allows the usege of global variable main_window and its functions
extern sf::RenderWindow* main_window;
extern int g_fps;
extern bool music_on;
extern bool sound_on;

class Scene {
public:
    /* Constructor */
    Scene(std::string map, sf::Text playername);

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

    /* Win screen */
    void DisplayVictoryScreen();

    /* Death sreen */
    void DisplayDeathScreen();

    /* Add projectiles to scene */
    void AddProjectiles(std::vector<Projectile*> projectiles);

    std::vector<GameObject*> GetObjects() { return map_.objects; }

    bool end_ = false;

private:
    Map map_;
    Player* player_;
    sf::Text playername_;
    sf::Text kills_;
    std::string killcount_;
    sf::Font font_;
    std::vector<Projectile*> projectiles_;
    sf::Texture cursor_;
    sf::Sprite cursor_sprite_;
    sf::Music music_; // Music that holds the game music
};
