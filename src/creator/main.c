/*
** Personnal Project, 2023
** game_of_life - creator
** File description:
** Created by Anthony Anicotte,
*/

#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <zconf.h>
#include <memory.h>
#include "struct.h"
#include "function_creator.h"

char **gen_map(creator_t *crea_struct)
{
    char **tab = malloc(sizeof(char *) * (crea_struct->lines + 3));

    //Malloc des lignes + le NULL
    for (int i = 0; i < crea_struct->lines + 3; i++)
        tab[i] = malloc(sizeof(char) * crea_struct->columns + 3);
    tab[crea_struct->lines + 2] = NULL;

    //Met les '-' au début et à la fin
    for (int i = 0; i < crea_struct->columns + 2; i++) {
        tab[0][i] = '-';
        tab[crea_struct->lines + 1][i] = '-';
    }

    //Mets les '\0' et les '|' à la fin des lignes
    for (int i = 1; i < crea_struct->lines + 1; i++) {
        tab[i][crea_struct->columns + 2] = '\0';
        tab[i][0] = '|';
        tab[i][crea_struct->columns + 1] = '|';
    }

    // on fill avec les espaces
    for (int i = 1; i < crea_struct->lines + 1; i++) {
        for (int j = 1; j < crea_struct->columns + 1; j++)
            tab[i][j] = ' ';
    }
    tab[1][1] = 'P';
    return (tab);
}

void init_struct(int columns, int lines, creator_t *crea_struct)
{
    crea_struct->p_pos = malloc(sizeof(position_t));
    crea_struct->p_pos->x = 1;
    crea_struct->p_pos->y = 1;
    crea_struct->nbr_max_dot = 0;
    crea_struct->dot_pos_x = malloc(
        sizeof(int) * (crea_struct->nbr_max_dot + 1));
    crea_struct->dot_pos_y = malloc(
        sizeof(int) * (crea_struct->nbr_max_dot + 1));
    crea_struct->columns = columns;
    crea_struct->dot_pos_x[0] = 0;
    crea_struct->dot_pos_y[0] = 0;
    crea_struct->lines = lines;
    crea_struct->empty_map = gen_map(crea_struct);
    crea_struct->dotty_map = gen_map(crea_struct);
}

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
            if (map[i][j] == 'P')
                map[i][j] = ' ';
    }
    fp = fopen(file_path, "w+");
    for (int i = 0; map[i] != NULL; i++) {
        fprintf(fp, map[i]);
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void print_usage(void)
{
    printf("./creator USAGES :\n\n- Use ./creator [WIDTH] [HEIGHT] [MAP_PATH]\n\n");
    printf("WIDTH : represents the width of the map (in characters)\n");
    printf("HEIGHT : represents the height of the map (in characters)\n");
    printf("MAP_PATH : represents the file where the map will be saved\n");
}

int main(int ac, char **av)
{
    if (ac == 1) {
        print_usage();
        return (0);
    }
//    if (error_handling(ac, av) != 0)
//        return (84);
    creator_t *crea_struct = malloc(sizeof(creator_t));
    init_struct(atoi(av[1]), atoi(av[2]), crea_struct);
    start_creator(crea_struct);
    fill_map(av[3], crea_struct);
    free_structure(crea_struct);
}