#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "constants.hpp"

class MenuButton {
public:
    MenuButton(const std::string& text, sf::Vector2f coordinates);

    ~MenuButton() = default;

    sf::RenderTexture& GetTexture() { return texture_; }

private:
    sf::RenderTexture texture_;
};