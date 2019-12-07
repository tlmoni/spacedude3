#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "GameObjects/wall.hpp"
#include "player.hpp"

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
    static std::pair<std::pair<std::string, PhysicsVector>, std::vector<GameObject*>> LoadMap(std::string filename) {
        std::ifstream is(filename); // Open the file to be read
        if (is.fail()) {
            is.close();
            std::cout << "Couldn't open the file!" << std::endl;
            exit(EXIT_FAILURE);
        }

        float x = 0.0f, y = 0.0f;
        PhysicsVector player_position;
        std::vector<GameObject*> game_objects;
        std::string line;

        while (std::getline(is, line)) {
            if (line == "#background") {
                std::getline(is, line);
            }

            else if (line == "#map") {
                while (std::getline(is, line)) {
                    x = 0.0f;
                    std::vector<std::string> line_objects = Split(line, '-');
                    for (auto object : line_objects) {
                        // Player 1
                        if (object == "1") {
                            player_position = PhysicsVector(x, y);
                        }

                        // Wall object
                        else if (object == "w") {
                            game_objects.push_back(new Wall(PhysicsVector(x, y)));
                        }
                        x += 64.f;
                    }
                    y += 64.f;
                }
            }
        }

        is.close();
        return std::pair<PhysicsVector, std::vector<GameObject*>>(player_position, game_objects);
    }
};
