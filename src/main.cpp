#include <iostream>
#include <SFML/Graphics.hpp>
#include "menu.hpp"
#include "scene.hpp"

// Define main_window and scene as global variables
sf::RenderWindow* main_window = new sf::RenderWindow(sf::VideoMode(1600, 900), "<insert game name here>"); // Main window, contains everything within the game
Scene* scene = new Scene(); // Contains & handles everything rendered to the main window
Menu* menu = new Menu();

//BUBBLEGUM
GameObject* map = new GameObject(sf::Vector2f(0.0f,0.0f),"src/Textures/maplarge.png");
//BUBBLEGUM END

int main() {
    menu->Init();

    delete menu;

    return 0;
}
