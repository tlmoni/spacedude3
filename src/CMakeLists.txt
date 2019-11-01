cmake_minimum_required(VERSION 2.5)
project(BrawlStars)
file(GLOB gamesrc
    *.cpp
    *.hpp
)
add_compile_options(-g -std=c++17 -Wall -Wextra -pedantic)
add_executable(BrawlStars ${gamesrc})