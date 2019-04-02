/*
** EPITECH PROJECT, 2019
** PROJECT
** File description:
** Created by Anthony Anicotte,
*/
#ifndef PROJECT_FUNCTION_H
#define PROJECT_FUNCTION_H

#include "struct.h"

void free_structure(game_of_life_t *gol_struct);
char **parse_map(char *str, game_of_life_t *gol_struct);
void print_tab(char **tab, int state);
int start_game(game_of_life_t *gol_struct);
void free_tab(char **tab);
char **copy_tab(char **map, int lines);
void clear_print_and_refresh(game_of_life_t *gol_struct);

#endif