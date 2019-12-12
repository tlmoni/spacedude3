#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>

extern sf::RenderWindow* main_window;

enum PlayerAnimationIndex {
    IDLE,
    MOVE,
    ANIM1,
    ANIM2,
    ANIM3
};

class Animation {
public:
    Animation() = default;

    Animation(std::string file, std::map<int, std::pair<int, int>> animation_map, int size, int move_delay, int anim1_delay, int anim2_delay);

    sf::Sprite NextFrame(int animation_index);

    sf::Sprite Stop(int animation_index);

    std::map<int, sf::Clock> timers_;
private:
    sf::Texture texture_;
    std::map<int, std::pair<int, int>> animations_;
    int size_;
    std::map<int, int> animation_delays_;
};