/*
** EPITECH PROJECT, 2023
** game_of_life
** File description:
** Created by Anthony Anicotte,
*/

#include "struct.h"
#include "function_creator.h"

void key_up(creator_t *crea_struct)
{
    if (crea_struct->p_pos->y > 1) {
        crea_struct->empty_map[crea_struct->p_pos->y][crea_struct->p_pos->x] = ' ';
        crea_struct->p_pos->y--;
        crea_struct->empty_map[crea_struct->p_pos->y][crea_struct->p_pos->x] = 'P';
    }
    clear_print_and_refresh(crea_struct);
}

void key_down(creator_t *crea_struct)
{
    if (crea_struct->p_pos->y < crea_struct->lines) {
        crea_struct->empty_map[crea_struct->p_pos->y][crea_struct->p_pos->x] = ' ';
        crea_struct->p_pos->y++;
        crea_struct->empty_map[crea_struct->p_pos->y][crea_struct->p_pos->x] = 'P';

    }
    clear_print_and_refresh(crea_struct);
}

void key_left(creator_t *crea_struct)
{
    if (crea_struct->p_pos->x > 1) {
        crea_struct->empty_map[crea_struct->p_pos->y][crea_struct->p_pos->x] = ' ';
        crea_struct->p_pos->x--;
        crea_struct->empty_map[crea_struct->p_pos->y][crea_struct->p_pos->x] = 'P';
    }
    clear_print_and_refresh(crea_struct);
}

void key_right(creator_t *crea_struct)
{
    if (crea_struct->p_pos->x < crea_struct->columns) {
        crea_struct->empty_map[crea_struct->p_pos->y][crea_struct->p_pos->x] = ' ';
        crea_struct->p_pos->x++;
        crea_struct->empty_map[crea_struct->p_pos->y][crea_struct->p_pos->x] = 'P';
    }
    clear_print_and_refresh(crea_struct);
}