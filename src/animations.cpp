#include "animations.hpp"

Animation::Animation(std::string file, std::map<int, std::pair<int, int>> animation_map, int size) {
    if (!texture_.loadFromFile(file)) {
        // error
    }
    animations_ = animation_map;
    size_ = size;
}

sf::Sprite Animation::NextFrame(int animation_index) {
    std::pair<int, int> frame = animations_[animation_index];
    sf::Sprite sprite;
    sprite.setTexture(texture_);
    sprite.setTextureRect(sf::Rect(frame.first*size_, animation_index*size_, size_, size_));

    frame.first++;
    if (frame.first > frame.second) {
        frame.first = 1;
    }
    animations_[animation_index] = frame;

    return sprite;
}

sf::Sprite Animation::Stop(int animation_index) {
    std::pair<int, int> frame = animations_[animation_index];
    frame.first = 0;
    sf::Sprite sprite;
    sprite.setTexture(texture_);
    sprite.setTextureRect(sf::Rect(frame.first*size_, animation_index*size_, size_, size_));

    frame.first = 0;
    animations_[animation_index] = frame;

    return sprite;
}