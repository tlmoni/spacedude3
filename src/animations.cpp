#include "animations.hpp"

Animation::Animation(std::string file, std::map<int, std::pair<int, int>> animation_map, int size, int move_delay, int anim1_delay, int anim2_delay) {
    if (!texture_.loadFromFile(file)) {
        // error
    }
    animations_ = animation_map;
    size_ = size;
    animation_delays_[MOVE] = move_delay;
    animation_delays_[ANIM1] = anim1_delay;
    animation_delays_[ANIM2] = anim2_delay;
}

sf::Sprite Animation::NextFrame(int animation_index) {
    std::pair<int, int> frame = animations_[animation_index];
    if (frame.first == 0) {
        frame.first = 1;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture_);
    sprite.setTextureRect(sf::Rect(frame.first*size_, animation_index*size_, size_, size_));

    if (timers_[animation_index].getElapsedTime().asMilliseconds() > animation_delays_[animation_index]) {
        timers_[animation_index].restart();

        frame.first++;
        if (frame.first > frame.second) {
            frame.first = 1;
        }
        animations_[animation_index] = frame;
    }
    sprite.setOrigin(26,32);

    return sprite;
}

sf::Sprite Animation::Stop(int animation_index) {
    timers_[animation_index].restart();
    std::pair<int, int> frame = animations_[animation_index];
    frame.first = 0;
    sf::Sprite sprite;
    sprite.setTexture(texture_);
    sprite.setTextureRect(sf::Rect(frame.first*size_, animation_index*size_, size_, size_));

    frame.first = 0;
    animations_[animation_index] = frame;

    sprite.setOrigin(26,32);

    return sprite;
}