# Brawl Stars

**Software Project for ELEC-A7151 Object oriented programming with C++**

Simo Hakanummi, Toni Lyttinen, Toni Ojala & Mikko Suhonen


![Image](./menu_500px.png) ![Image](./gameplay_500px.png)


### Features

* A [Brawl Stars](https://supercell.com/en/games/brawlstars/)-like game
* A real-time game
* 2D-graphics (top-down view)
* Pixelated art style
* The game has self-drawn graphics and self-composed soundtrack
* The goal was to create an audio-visually pleasing game that is fun to play.
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
* Number button 1,2,3 to change between tools.
* 1 (Blaster), 2 (Shotgun), 3 (Medikit).

### Gameplay

* The target is to stay alive, destroy ALL the enemies and find the goal teleporter.
* Shoot the enemies with your blaster
* Shooting at enemies depletes their hitpoints
* When hitpoints reach zero, an entity dies
* Avoid getting hit by enemies to remain alive

### Map creation
* There is an easy way to create your own map for the game.
* One only needs an text editor and some general format information.
* Maps folder is located within the src folder.
* One can edit any of the available maps in the folder.
* Do not rename the maps, their names are coded into the games menu system.
* First three lines specify the gamemode, the empty line is crucial for the maploaders function.
    #gamemode
    campaign

* Second batch of three lines specify the map background files location.
    #background
    src/Textures/background_red.png

* After the aforementioned two have been specified it is time to build the map, here is an example.
    #map
    w-w-w-w-w   // w = Wall
    w-.-P-.-w   // P = Player spawn point
    w-.-.-.-w   // Z = Zombie spawn point
    w-.-Z-.-w   // d = Breakable crate
    w-.-.-.-w   // X = Teleport that activates once all zombies are killed
    w-.-.-.-W   // S = Zombie spawner in survival mode
    w-d-d-d-w   // . = Empty space
    w-.-.-.-w   // All building block symbols need to be separated from another by a dash.
    w-.-X-.-w   // For example w-.-P-.-w
    w-w-w-w-w
* Check the premade maps for ideas and more clarity on the formatting of the maps.

### Implementation Details

We used [SFML](https://www.sfml-dev.org/) library to implement
our graphics, sounds and game structure.
We decided to use it because it seemed easy to use and suitable for our usage.
Also we were encouraged to use SFML by our project topic page.

Originally we were set on implementing network features into the game.
But since it would have drastically cut into everything else and could have demanded a total overhaul of the code
we had written so far. With time contraints in mind, we decided against it.