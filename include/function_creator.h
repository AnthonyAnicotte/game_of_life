/*
** EPITECH PROJECT, 2023
** game_of_life
** File description:
** Created by Anthony Anicotte,
*/
#ifndef GAME_OF_LIFE_FUNCTION_CREATOR_H
#define GAME_OF_LIFE_FUNCTION_CREATOR_H

#include "struct.h"

void free_tab(char **tab);
void free_structure(creator_t *crea_struct);
void print_tab(char **tab);
void start_creator(creator_t *crea_struct);
void clear_print_and_refresh(creator_t *crea_struct);

void key_up(creator_t *crea_struct);
void key_down(creator_t *crea_struct);
void key_right(creator_t *crea_struct);
void key_left(creator_t *crea_struct);
void space(creator_t *crea_struct);
#endif //GAME_OF_LIFE_FUNCTION_CREATOR_H
