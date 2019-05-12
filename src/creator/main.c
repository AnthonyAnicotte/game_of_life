/*
** Personnal Project, 2023
** game_of_life - creator
** File description:
** Created by Anthony Anicotte,
*/

#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <zconf.h>
#include <memory.h>
#include "struct.h"
#include "function_creator.h"

int search_flag_place(char **av, char flag)
{
    int place_flag = 0;

    for (; av[place_flag] != NULL && av[place_flag][1] != flag; place_flag++);
    if (av[place_flag] == NULL)
        return (-1);
    return (place_flag);
}

void print_usage(void)
{
    printf("./creator USAGES :\n\n- Use ./creator [WIDTH] [HEIGHT] [MAP_PATH]\n\n");
    printf("WIDTH : represents the width of the map (in characters)\n");
    printf("HEIGHT : represents the height of the map (in characters)\n");
    printf("MAP_PATH : represents the file where the map will be saved\n\n");
    printf("RANDOM_PC : represents the percentage for the automatic generation");
    printf("Commands:\n\n- Arrow keys to move your character\n- Space to place");
    printf("/remove a dot\n- Key R or BackSpace to reset the map\n- Enter to");
    printf("save the map\n");
}

int main(int ac, char **av)
{
    if (ac == 1 || strcmp(av[1], "-h") == 0 || strcmp(av[1], "--help") == 0) {
        print_usage();
        return (0);
    }
    if (error_handling_creator(av) != 0)
        return (84);
    creator_t *crea_struct = malloc(sizeof(creator_t));

    init_struct(av, crea_struct);
    if (start_creator(crea_struct, av) != 0) {
        free_structure(crea_struct);
        return (0);
    }
    fill_map(av[search_flag_place(av, 'f') + 1], crea_struct);
    if (crea_struct->random_pc != -1)
        print_map(av[search_flag_place(av, 'f') + 1], crea_struct);
    free_structure(crea_struct);
}
