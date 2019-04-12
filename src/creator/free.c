#include <stdlib.h>

/*
** EPITECH PROJECT, 2023
** game_of_life
** File description:
** Created by Anthony Anicotte,
*/

#include "struct.h"

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

void free_structure(creator_t *crea_struct)
{
    free_tab(crea_struct->empty_map);
    free(crea_struct->p_pos);
    free(crea_struct->dot_pos_x);
    free(crea_struct->dot_pos_y);
    free(crea_struct);
}