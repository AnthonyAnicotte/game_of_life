/*
** EPITECH PROJECT, 2023
** game_of_life
** File description:
** Created by Anthony Anicotte,
*/
#ifndef GAME_OF_LIFE_STRUCT_H
#define GAME_OF_LIFE_STRUCT_H

typedef struct game_of_life_s
{
    unsigned long int generation;
    int speed;
    char **map;
    int columns;
    int lines;
} game_of_life_t;

typedef struct position_s
{
    int x;
    int y;
} position_t;

typedef struct creator_s
{
    int random_pc;
    char **empty_map;
    char **dotty_map;
    int lines;
    int columns;
    position_t *p_pos;
    int *dot_pos_x;
    int *dot_pos_y;
    int nbr_max_dot;
} creator_t;
#endif //GAME_OF_LIFE_STRUCT_H
