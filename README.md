# game_of_life
Personnal Project based on the Game Of Life

This program is a simulation of the Game Of Life, created by Pr John Herton Conway in 1970.
It uses the ncurses library.


You have to use the 'make' command to compile the project.

Usage: ./conway [map] [speed]

Generation per Second becomes 'GPS'

If you don't precise the number of GPS, you'll have to press space bar to skip generations
You can find examples for maps in the folder maps/


Map restrictions:

- The dead cells are represented by spaces and alive cells by dots.
- The borders of the map must be the same as in the example.
- All the lines should have the same number of characters.


Known Bugs:

- No error handling for maps and argument [COMING SOON]


Update Log:


April 3rd, 2019:
- New functionnality: Add an integer after the map argument to precize the GPS

April 2nd, 2019:
- First push of the project without error handling


Notes:

Some Features will coming in the future.

Features already implemented:

- GPS handling (speed)