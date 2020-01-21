# Spacedude 3: Return of the Zombies

**Software Project for ELEC-A7151 Object oriented programming with C++**

Simo Hakanummi, Toni Lyttinen, Toni Ojala & Mikko Suhonen


This is the git repository for our programming project.
It contains the following directories:

* `build/` -- Directory containing the compiled objects and binaries (executive)

* `doc/` -- Directory containing the documentation of the project

* `plan/` -- Contains the following:
- The project plan
- Git workflow instructions for the development of the project
- Style guide for our project (basic 'rules' for coding style)

* `src/` -- Contains all the source code and other needed sources (e.g. textures and images)

* `README.md` -- This file. Contains overview of the project and repository

* `How to build` -- Intructions are located in build/ directory (BuildInstructions.txt)

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
