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
    char **map;
    int columns;
    int lines;
} game_of_life_t;

#endif //GAME_OF_LIFE_STRUCT_H
