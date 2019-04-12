/*
** EPITECH PROJECT, 2023
** game_of_life
** File description:
** Created by Anthony Anicotte,
*/

#include <stdlib.h>
#include <getopt.h>
#include <stdio.h>
#include <zconf.h>
#include <fcntl.h>
#include "function_creator.h"
#include "struct.h"

void print_map(char *file_path, creator_t *crea_struct)
{
    int fd;
    int size = (crea_struct->columns + 3) * (crea_struct->lines + 2);
    char *buffer = malloc(sizeof(char) * size + 1);

    fd = open(file_path, O_RDONLY);
    read(fd, buffer, size);
    buffer[size] = '\0';
    printf("Your map have been generated in '%s'\n\n%s:\n%s\n", file_path,
        file_path, buffer);
    free(buffer);
    close(fd);
}

int get_percentage(char **av)
{
    int percentage = 0;

    for (int i = 0; av[i] != NULL; i++)
        if (av[i][1] == 'r')
            percentage = atoi(av[i + 1]);
    return (percentage);
}

int flag_r_option(creator_t *crea_struct, int ac, char **av)
{
    int options;

    while ((options = getopt(ac, av, "r")) != -1) {
        if (options == 'r') {
            crea_struct->random_pc = get_percentage(av);
            return (0);
        }
    }
    return (1);
}

void create_the_dot(creator_t *crea_struct, int x, int y)
{
    int random = rand() % 100;

    if (random < crea_struct->random_pc)
        create_new_dot(crea_struct, x, y);
}

void automatic_gen_map(creator_t *crea_struct)
{
    for (int y = 1; y <= crea_struct->lines; y++) {
        for (int x = 1; x <= crea_struct->columns; x++)
            create_the_dot(crea_struct, x, y);
    }
}