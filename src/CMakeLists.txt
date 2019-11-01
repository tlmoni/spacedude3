cmake_minimum_required(VERSION 2.6)
project(BrawlStars)
file(GLOB gamesrc
    *.cpp
    *.hpp
)
add_compile_options(-g -std=c++17 -Wall -Wextra -pedantic -I $(SFML)/include)
add_executable(BrawlStars ${gamesrc})

# If you want to link SFML statically
set(SFML_STATIC_LIBRARIES TRUE)

# In most cases better set in the CMake cache
set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS SFML::system SFML::window SFML::graphics SFML::audio SFML::network REQUIRED)
add_executable(BrawlStars main.cpp)
target_link_libraries(BrawlStars sfml-system sfml-window sfml-graphics sfml-audio sfml-network)