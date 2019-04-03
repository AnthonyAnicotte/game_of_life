/*
** EPITECH PROJECT, 2023
** game_of_life
** File description:
** Created by Anthony Anicotte,
*/

#include <stdlib.h>
#include "struct.h"

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

void free_structure(game_of_life_t *gol_struct)
{
    free_tab(gol_struct->map);
    free(gol_struct);
}