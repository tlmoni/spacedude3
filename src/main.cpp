#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "scene.hpp"
#include "menu.hpp"
#include "scene.hpp"

// Define main_window and scene as global variables
sf::RenderWindow* main_window = new sf::RenderWindow(sf::VideoMode(800, 800), "<insert game name here>"); // Main window, contains everything within the game

Scene* scene = new Scene(); // Contains & handles everything rendered to the main window
Menu* menu = new Menu();

int g_fps = 60;
double g_friction = 1.3f;



int main() {
    menu->Init();

    delete menu;

    return 0;
}
