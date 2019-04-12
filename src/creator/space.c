/*
** EPITECH PROJECT, 2023
** game_of_life
** File description:
** Created by Anthony Anicotte,
*/

#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <zconf.h>
#include "function_creator.h"
#include "struct.h"

int there_is_a_dot_under_the_guy(creator_t *crea_struct)
{
    for (int i = 1; i <= crea_struct->nbr_max_dot; i++) {
        if (crea_struct->p_pos->x != crea_struct->dot_pos_x[i] ||
            crea_struct->p_pos->y != crea_struct->dot_pos_y[i])
            sleep(0);
        else
            return (i);
    }
    return (-1);
}

void create_new_dot(creator_t *crea_struct, int x, int y)
{
    crea_struct->nbr_max_dot++;
    crea_struct->dot_pos_x = realloc(crea_struct->dot_pos_x,
        sizeof(int) * (crea_struct->nbr_max_dot + 1));
    crea_struct->dot_pos_y = realloc(crea_struct->dot_pos_y,
        sizeof(int) * (crea_struct->nbr_max_dot + 1));
    crea_struct->dot_pos_x[crea_struct->nbr_max_dot] = x;
    crea_struct->dot_pos_y[crea_struct->nbr_max_dot] = y;
}

void delete_this_dot(creator_t *crea_struct, int dot)
{
    for (int i = dot; i < crea_struct->nbr_max_dot; i++) {
        crea_struct->dot_pos_x[i] = crea_struct->dot_pos_x[i + 1];
        crea_struct->dot_pos_y[i] = crea_struct->dot_pos_y[i + 1];
    }
    crea_struct->nbr_max_dot--;
    crea_struct->dot_pos_x = realloc(crea_struct->dot_pos_x,
        sizeof(int) * crea_struct->nbr_max_dot + 1);
    crea_struct->dot_pos_y = realloc(crea_struct->dot_pos_y,
        sizeof(int) * (crea_struct->nbr_max_dot + 1));
}

void space(creator_t *crea_struct)
{
    int flag = there_is_a_dot_under_the_guy(crea_struct);

    if (flag == -1)
        create_new_dot(crea_struct, crea_struct->p_pos->x, crea_struct->p_pos->y);
    else
        delete_this_dot(crea_struct, flag);
    clear_print_and_refresh(crea_struct);
}