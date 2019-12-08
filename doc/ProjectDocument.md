# Brawl Stars

**Software Project for ELEC-A7151 Object oriented programming with C++**

Simo Hakanummi, Toni Lyttinen, Toni Ojala & Mikko Suhonen

![Image](./menu_500px.png) ![Image](./gameplay_500px.png)

### Features

* A Brawl Stars-like game
* A real-time game
* 2D-graphics (top-down view)
* Pixelated art style
* The game has self-drawn graphics and self-composed soundtrack
* The goal was to create an audio-visually pleasing game that is fun to play
* Generally, the idea was to create a solid base structure for the game that can be extended and developed even after the course.

### Install dependencies

    sudo apt-get install libsfml-dev

### Compile and Run

Once you have the dependencies (see above), run the following command in your terminal:

    make run

### Controls

* WASD to move up, left, down an right
* Move mouse cursor to aim
* Mouse left click to shoot (hold for fully automatic fire)

### Gameplay

* The target is to stay alive and complete the mission
* Shoot the enemies with your blaster
* Shooting at enemies depletes their hitpoints
* When hitpoints reach zero, an entity dies
* Avoid getting hit enemies to remain alive

### Implementation Details

We used [SFML](https://www.sfml-dev.org/) library to implement
our graphics, sounds and game structure.
We decided to use it because it seemed easy to use and suitable for our usage.
Also we were encouraged to use SFML by our project topic page.

*Under construction*
