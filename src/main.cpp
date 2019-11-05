#include <iostream>
#include <SFML/Graphics.hpp>
#include "scene.hpp"

sf::RenderWindow* main_window = new sf::RenderWindow(sf::VideoMode(1600, 900), "<insert game name here>");
Scene* scene = new Scene();

int main() {

    scene->Init();

    delete scene;

    return 0;
}
