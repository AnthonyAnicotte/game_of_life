# Game Of Life

Personnal Project based on the Game Of Life, created by Pr John Herton Conway in 1970.
It uses the ncurses library

# Compilation

Use the command 'make' at the root of the repository to compile the project

```sh
$ make
```

# How to use the 'creator mode'

You can access to the help guide by typing these commands
```sh
$ ./creator
$ ./creator -h
$ ./creator --help
```
To create your own map, execute the following command

```sh
./creator -x [WIDTH] -y [HEIGHT] -f [PATH] {OPTIONNAL: -r [AUTO-GEN]}
```
[WIDTH] : Corresponds to the width of the map
[HEIGHT] : Corresponds to the height of the map
[PATH] : Corresponds to the path of the file where the map will be saved.

{OPTIONNAL} : Optionnal flags, unnecessary to run the program
- '-r' : Automatic generation. You define the percentage of filling of the map 

## Comments
- You can write the flags in the order you want. '-x' '-y' and '-f' are mandatory
- Be careful when you choose the file path, it replaces the totality of the file data
- To have a graphical square, WIDTH should be 2* HEIGHT
- You'll find commands in help guide and in the creator

# How to use the 'simulation mode'

You can access  to the help guide by typing these commands

```sh
./conway
./conway -h
./conway --help
```

To launch the simulation, execute the following command
```sh
./conway -f [PATH] {OPTIONNAL: -a [SPEED]}
```
[PATH] : Corresponds to the path of the map that will be simulated

{OPTIONNAL}: Optionnal flags, unnecessary to run the program
- '-a' : Automatic simulation. The speed is defined by the flag you entered. It's expressed in Generation Per Second (By default, manual mode is enabled)

## Comments
- The manual mode is the default mode if you don't precize the speed
- You'll find commands in help guide and in the simulation
- /!\ The actual version of the simulator is not update. Use ./conway [PATH] [SPEED] to launch the simulation

The map have several restrictions:
-- The dead cells are represented by spaces and alive cells by dots
-- The borders of the map must be the same as in the example.
-- All the lines should have the same number of characters.

# Known Bugs

- Simulator not updated yet (Coming Soon)
- Feel free to post issues on the associated category on GitHub

# Update log

April 11th, 2019:
- Modified the arguments parsing system and corrected segfault/memory leaks

April 10th, 2019:
- Automatic generation is now available with the '-r' flag

April 4th, 2019:
- Added usages and print_commands for user comfort

April 3rd, 2019:
- Added a new feature/program: You now have the creator mode to create your own maps !


April 3rd, 2019:
- New functionnality: Add an integer after the map argument to precize the GPS

April 2nd, 2019:
- First push of the project without error handling

