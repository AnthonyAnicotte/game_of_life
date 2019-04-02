/*
** EPITECH PROJECT, 2023
** game_of_life
** File description:
** Created by Anthony Anicotte,
*/

#include <stdlib.h>
#include "struct.h"

int get_nbr_lines(char *map)
{
    int i = 0;
    int lines = 0;

    for (i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n')
            lines++;
    }
    if (map[i - 1] != '\n')
        lines++;
    return (lines);
}

int get_nbr_columns(char *map)
{
    int i;

    for (i = 0; map[i] != '\0' && map[i] != '\n'; i++);
    return (i);
}

char *get_line(int *cpt, char *str, int size_str)
{
    char *line = malloc(sizeof(char) * size_str + 1);
    int i = 0;

    while (str[(*cpt)] != '\n' && str[(*cpt)] != '\0') {
        line[i] = str[*cpt];
        (*cpt)++;
        i++;
    }
    (*cpt)++;
    line[i] = '\0';
    return (line);
}

char **parse_map(char *str, game_of_life_t *gol_struct)
{
    char **tab;
    int cpt = 0;

    gol_struct->lines = get_nbr_lines(str);
    gol_struct->columns = get_nbr_columns(str);
    tab = malloc(sizeof(char *) * (gol_struct->lines + 1));
    for (int i = 0; i < gol_struct->lines; i++)
        tab[i] = get_line(&cpt, str, gol_struct->columns);
    tab[gol_struct->lines] = NULL;
    return (tab);
}