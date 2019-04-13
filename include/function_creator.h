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
int start_creator(creator_t *crea_struct, char **av);
void clear_print_and_refresh(creator_t *crea_struct);
int there_is_a_dot_under_the_guy(creator_t *crea_struct);
void automatic_gen_map(creator_t *crea_struct);
void create_new_dot(creator_t *crea_struct, int x, int y);
void print_map(char *file_path, creator_t *crea_struct);
int error_handling_creator(char **av);
int my_str_isnum(char const *str);
int search_flag_place(char **av, char flag);
void init_struct(char **av, creator_t *crea_struct);
void fill_map(char *file_path, creator_t *crea_struct);

void key_up(creator_t *crea_struct);
void key_down(creator_t *crea_struct);
void key_right(creator_t *crea_struct);
void key_left(creator_t *crea_struct);
void space(creator_t *crea_struct);
#endif //GAME_OF_LIFE_FUNCTION_CREATOR_H
