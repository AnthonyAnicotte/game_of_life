/*
** EPITECH PROJECT, 2023
** game_of_life
** File description:
** Created by Anthony Anicotte,
*/

#include <stdlib.h>
#include <stdio.h>
#include <zconf.h>
#include <memory.h>
#include "struct.h"
#include "function_creator.h"

void fill_map(char *file_path, creator_t *crea_struct)
{
    FILE *fp;
    char **map = malloc(sizeof(char *) * (crea_struct->lines + 3));

    for (int i = 0; crea_struct->empty_map[i] != NULL; i++)
        map[i] = strdup(crea_struct->empty_map[i]);
    map[crea_struct->lines + 2] = NULL;
    for (int i = 1; i <= crea_struct->nbr_max_dot; i++)
        map[crea_struct->dot_pos_y[i]][crea_struct->dot_pos_x[i]] = '.';
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++)
            if (map[i][j] == 'F')
                map[i][j] = ' ';
    }
    fp = fopen(file_path, "w+");
    for (int i = 0; map[i] != NULL; i++) {
        fprintf(fp, map[i]);
        fprintf(fp, "\n");
    }
    fclose(fp);
}

char **gen_map(creator_t *crea_struct)
{
    char **tab = malloc(sizeof(char *) * (crea_struct->lines + 3));

    for (int i = 0; i < crea_struct->lines + 3; i++)
        tab[i] = malloc(sizeof(char) * crea_struct->columns + 3);
    tab[crea_struct->lines + 2] = NULL;
    for (int i = 0; i < crea_struct->columns + 2; i++) {
        tab[0][i] = '-';
        tab[crea_struct->lines + 1][i] = '-';
    }
    for (int i = 1; i < crea_struct->lines + 1; i++) {
        tab[i][crea_struct->columns + 2] = '\0';
        tab[i][0] = '|';
        tab[i][crea_struct->columns + 1] = '|';
    }
    for (int i = 1; i < crea_struct->lines + 1; i++) {
        for (int j = 1; j < crea_struct->columns + 1; j++)
            tab[i][j] = ' ';
    }
    tab[1][1] = 'F';
    return (tab);
}

void init_struct(char **av, creator_t *crea_struct)
{
    crea_struct->random_pc = -1;
    crea_struct->p_pos = malloc(sizeof(position_t));
    crea_struct->p_pos->x = 1;
    crea_struct->p_pos->y = 1;
    crea_struct->nbr_max_dot = 0;
    crea_struct->dot_pos_x = malloc(
        sizeof(int) * (crea_struct->nbr_max_dot + 1));
    crea_struct->dot_pos_y = malloc(
        sizeof(int) * (crea_struct->nbr_max_dot + 1));
    crea_struct->columns = atoi(av[search_flag_place(av, 'x') + 1]);
    crea_struct->dot_pos_x[0] = 0;
    crea_struct->dot_pos_y[0] = 0;
    crea_struct->lines = atoi(av[search_flag_place(av, 'y') + 1]);;
    crea_struct->empty_map = gen_map(crea_struct);
    crea_struct->dotty_map = gen_map(crea_struct);
}