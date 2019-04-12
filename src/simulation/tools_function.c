/*
** EPITECH PROJECT, 2023
** game_of_life
** File description:
** Created by Anthony Anicotte,
*/

#include <memory.h>
#include <ncurses.h>
#include "function_simulator.h"
#include "stdlib.h"
#include "struct.h"

char **copy_tab(char **map, int lines)
{
    char **tab = malloc(sizeof(char *) * (lines + 1));

    for (int i = 0; map[i] != NULL; i++)
        tab[i] = strdup(map[i]);
    tab[lines] = NULL;
    return (tab);
}

void clear_print_and_refresh(game_of_life_t *gol_struct)
{
    clear();
    print_tab(gol_struct->map, gol_struct->generation);
    printw("\n\nPress Space in manual mode to skip a generation\n");
    refresh();
}