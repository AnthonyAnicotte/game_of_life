/*
** EPITECH PROJECT, 2023
** game_of_life
** File description:
** Created by Anthony Anicotte,
*/

#include <stdlib.h>
#include <stdio.h>
#include <zconf.h>
#include <fcntl.h>
#include "function_creator.h"
#include "struct.h"

void print_map(char *file_path, creator_t *crea_struct)
{
    int fd;
    size_t size = (size_t)(crea_struct->columns + 3) * (crea_struct->lines + 2);
    char *buffer = malloc(sizeof(char) * size + 1);

    fd = open(file_path, O_RDONLY);
    read(fd, buffer, size);
    buffer[size] = '\0';
    printf("Your map have been generated in '%s'\n\n%s:\n%s\n", file_path,
        file_path, buffer);
    free(buffer);
    close(fd);
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