/*
** Personnal project
** game_of_life by Pr John Conway
** File description:
** Created by Anthony Anicotte,
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <ncurses.h>
#include "struct.h"
#include "function_simulator.h"

void get_tab_from_map_str(char *map_path, game_of_life_t *gol_struct)
{
    char *map_str;
    int fd;
    struct stat filestat;

    stat(map_path, &filestat);
    map_str = malloc(sizeof(char) * filestat.st_size + 1);
    fd = open(map_path, O_RDONLY);
    read(fd, map_str, (size_t)filestat.st_size);
    map_str[(int)filestat.st_size] = '\0';
    gol_struct->map = parse_map(map_str, gol_struct);
    free(map_str);
}

void print_tab(char **tab, unsigned long int state)
{
    printw(
        "Simulation of 'The Game Of life by Pr John Conway\n      Adapted in C "
        "by Anthony Anicotte\n\n\n");
    printw("                 Generation n°%d\n", state);
    for (int i = 0; tab[i] != NULL; i++) {
        printw("                 %s\n", tab[i]);
    }
}

void print_usage(void)
{
    printf("./conway USAGES:\n\n- Use ./creator [MAP_PATH] [SPEED:optional]\n\n");
    printf("MAP_PATH : represents the path where the map will be read\n");
    printf("SPEED : represents the Generations per second, do not write if you"
           "want the manual mode\n\n");
    printf("Press Space in manual mode to skip a generation\n");
}

int main(int ac, char **av)
{
    game_of_life_t *gol_struct;

    if (ac == 1) {
        print_usage();
        return (0);
    }
    //    if (error_handling(ac, av) == 1)
    //        return (84);
    gol_struct = malloc(sizeof(game_of_life_t));
    gol_struct->generation = 0;
    if (av[2] != NULL)
        gol_struct->speed = atoi(av[2]);
    get_tab_from_map_str(av[1], gol_struct);
    start_game(gol_struct);
    free_structure(gol_struct);
}