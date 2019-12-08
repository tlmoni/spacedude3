## Laser Squad - ELEC-A7151 Object oriented programming with C++


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

    Install SFML:
    $ sudo apt-get install libsfml-dev

    - Navigate to repository root (this directory)
    - $ make all (just compile the project)
    - $ make run (clean previous build, compile and run the executive)
    - $ make clean (in case you want to clear the build)

    Install Valgrind:
    $ sudo apt-get install valgrind
    - Ran with a command specifying options and program to be tested
    - Command utilized for this project: "valgrind -v  --leak-check=yes ./BrawlStars"