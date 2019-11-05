#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

class MenuButton {
public:
    MenuButton(sf::Vector2f coordinates, const std::string& file);

    ~MenuButton() = default;

    sf::Sprite& GetSprite() { return sprite_; }

private:
    sf::Sprite sprite_;
};