#include "menubutton.hpp"

MenuButton::MenuButton(sf::Vector2f coordinates, const std::string& file) {
    sf::Texture texture;
    texture.loadFromFile(file);
    sprite_.setTexture(texture);
    sprite_.setPosition(coordinates);
}