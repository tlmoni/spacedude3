#pragma once

#include <iostream>
#include <vector>
#include <SFML/Window.hpp>

enum WindowState {
    OPEN = 0,
    CLOSED = -1
};

class EventHandler {
public:
    EventHandler() = default;

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

    /* Process events using input handler */
    int ProcessEvents(sf::Event& event) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                Add(event.key.code);
                return OPEN;

            case sf::Event::KeyReleased:
                Remove(event.key.code);
                return OPEN;

            case sf::Event::Closed:
                return CLOSED;

            default:
                return OPEN;
        }
        return OPEN;
    }

    std::vector<sf::Keyboard::Key>& GetKeys() { return keys_; }

private:
    std::vector<sf::Keyboard::Key> keys_;

};
