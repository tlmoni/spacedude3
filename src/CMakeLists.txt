cmake_minimum_required(VERSION 2.5)
project(BrawlStars)
file(GLOB gamesrc
    *.cpp
    *.hpp
)
add_compile_options(-g -std=c++17 -Wall -Wextra -pedantic -lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -lsfml-audio)
add_executable(BrawlStars ${gamesrc})