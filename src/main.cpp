#include <iostream>
#include <SFML/Graphics.hpp>
#include "scene.hpp"
#include "menu.hpp"

// Define main_window and scene as global variables
sf::RenderWindow* main_window = new sf::RenderWindow(sf::VideoMode(1600, 900), "<insert game name here>"); // Main window, contains everything within the game
Scene* scene = new Scene(); // Contains & handles everything rendered to the main window
Menu* menu = new Menu();
int main() {
    menu->Init();

    delete menu;

    return 0;
}
