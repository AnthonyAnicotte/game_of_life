# game_of_life
Personnal Project based on the Game Of Life

This program is a simulation of the Game Of Life, created by Pr John Herton Conway in 1970.
It uses the ncurses library.


You have to use the 'make' command to compile the project.

Usage of the simulator: ./conway [map] [speed]

Usage of the creator: ./conway [width] [height] [map_path]


"How to use the creator mode ?"

You juste have to launch the ./creator binary according to the usage upper and start editing.
Press space bar to place a dot and again to remove him
To save your map, press the ENTER key



Generation per Second becomes 'GPS'

If you don't precise the number of GPS, you'll have to press space bar to skip generations
You can find examples for maps in the folder maps/


Map restrictions:

- The dead cells are represented by spaces and alive cells by dots.
- The borders of the map must be the same as in the example.
- All the lines should have the same number of characters.


Known Bugs:

- No error handling for maps and argument [COMING SOON]
- No error handling in creator mode
- Coding Style


Update Log:

April 3rd, 2019:
- Added a new feature/program: You now have the creator mode to create your own maps !


April 3rd, 2019:
- New functionnality: Add an integer after the map argument to precize the GPS

April 2nd, 2019:
- First push of the project without error handling


Notes:

Some Features will come in the future.

Features already implemented:

- Creator Mode
- GPS handling (speed)