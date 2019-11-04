#pragma once

#include <iostream>
#include <vector>
#include <SFML/Window.hpp>




class InputHandler {
public:
    InputHandler() = default;

    void Add(sf::Keyboard::Key& key) {
        keys_.push_back(key);
    }

    void Remove(sf::Keyboard::Key& key) {
        for (auto it  = keys_.begin(); it != keys_.end(); it++) {
            if (*it == key) {
                keys_.erase(it);
            }
        }
    }

    std::vector<sf::Keyboard::Key>& GetKeys() { return keys_; }

private:
    std::vector<sf::Keyboard::Key> keys_;

};