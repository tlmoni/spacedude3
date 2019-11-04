#include <iostream>
#include <SFML/Graphics.hpp>
#include "scene.hpp"

int main() {
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1600, 900), "<insert game name here>");
    
    Scene scene = Scene(window);
    scene.Init();

    int a = 1;
    a += 1;

    return 0;
}
