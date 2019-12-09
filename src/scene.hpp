#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "maploader.hpp"

/*
class Animations {
public:
    Animations(std::vector<std::string> files) {
        files_ = files;
        sf::Texture texture;
        for (auto file : files) {
            if(!texture.loadFromFile(file)) {
                std::cout << "Error loading animations." << std::endl;
            }
            textures_.push_back(texture);
        }
    }
    std::vector<std::string> files_;
    std::vector<sf::Texture> textures_;
    sf::Clock animation_clock_;
    int animation_state_ = 0;
};
*/


class GameObject;

// Allows the usege of global variable main_window and its functions
extern sf::RenderWindow* main_window;
extern int g_fps;
extern bool music_on;
extern bool sound_on;

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

    void AddProjectiles(std::vector<Projectile*> projectiles);

    std::vector<GameObject*> GetObjects() { return map_.objects; }

    bool end_ = false;
    // Animations player_animations_ = Animations({"ekatexture", "tokatexture", "kolmastexture"});

private:
    Map map_;
    sf::Texture background_;
    Player* player_;
    std::vector<Projectile*> projectiles_;
    sf::Texture cursor_;
    sf::Sprite cursor_sprite_;
    sf::Music music_; // Music that holds the game music
};
