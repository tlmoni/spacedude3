#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "GameObjects/wall.hpp"
#include "GameObjects/zombie.hpp"
#include "player.hpp"

struct Map {
    std::string background_file;
    PhysicsVector player_location;
    std::vector<GameObject*> objects;
    std::vector<Zombie*> enemies;
    GameObject goal = GameObject(PhysicsVector(0, 0), "src/Textures/portal.png", RectHitbox(21.f, 21.f));
};

class MapLoader {
public:
    /* Helper method to split a string given as input. Return a vector containing the token split by the delimiter */
    static std::vector<std::string> Split(std::string str, char delim) {
        std::vector<std::string> split;
        std::stringstream ss(str);
        std::string token;
        while (std::getline(ss, token, delim)) {
            split.push_back(token);
        }
        return split;
    }

    /* Read the map file given as parameter and create game objects according to it.
    Returns a pair containing the Player's coordinate vector and a vector (container) of GameObjects in the map. */
    static Map LoadMap(std::string filename) {
        std::ifstream is(filename); // Open the file to be read
        if (is.fail()) {
            is.close();
            std::cout << "Couldn't open the file!" << std::endl;
            exit(EXIT_FAILURE);
        }

        float x = 0.0f, y = 0.0f;
        Map map;
        std::string line;

        while (std::getline(is, line)) {
            if (line == "#background") {
                std::getline(is, line);
                map.background_file = line;
            }

            else if (line == "#map") {
                while (std::getline(is, line)) {
                    x = 0.0f;
                    std::vector<std::string> line_objects = Split(line, '-');
                    for (auto object : line_objects) {
                        // Player
                        if (object == "P") {
                            map.player_location = PhysicsVector(x + 32, y + 32);
                        }

                        // Wall object
                        else if (object == "w") {
                            Wall* wall = new Wall(PhysicsVector(x, y), "src/Textures/crate.png");
                            map.objects.push_back(wall);
                        }

                        // Zombie
                        else if (object == "Z") {
                            Zombie* zombie = new Zombie(PhysicsVector(x + 32, y + 32));
                            map.objects.push_back(zombie);
                            map.enemies.push_back(zombie);
                        }

                        else if (object == "X") {
                            map.goal.SetPosition(PhysicsVector(x, y));
                            map.goal.SetOrigin(47, 47);
                            map.goal.collidable_ = false;
                        }

                        x += 64.f;
                    }

                    y += 64.f;
                }
            }
        }

        is.close();
        return map;
    }
};
