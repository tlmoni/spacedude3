#include <iostream>
#include <SFML/System.hpp>
#include "menu.hpp"

// Define main_window and scene as global variables
sf::RenderWindow* main_window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "<insert game name here>"); // Main window, contains everything within the game

Scene* scene = new Scene();
Menu* menu = new Menu();

int g_fps = 60;
float g_friction = 1.3f;
bool music_on = true;
bool sound_on = true;


int main() {
    menu->Init();

    delete menu;
    delete scene;
    delete main_window;

    return 0;
}
