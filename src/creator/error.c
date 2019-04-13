/*
** EPITECH PROJECT, 2023
** game_of_life
** File description:
** Created by Anthony Anicotte,
*/

#include <zconf.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "function_creator.h"

int all_flags_here(char **av)
{
    if (search_flag_place(av, 'x') == -1)
        return (1);
    if (search_flag_place(av, 'y') == -1)
        return (1);
    if (search_flag_place(av, 'f') == -1)
        return (1);
    return (0);
}

int valid_int_flag(char **av, char to_test)
{
    int place_flag = search_flag_place(av, to_test);

    if (av[place_flag + 1] == NULL)
        return (1);
    if (my_str_isnum(av[place_flag + 1]) == 1)
        return (1);
    if (av[place_flag][1] != 'r' && atoi(av[place_flag + 1]) < 1)
        return (1);
    return (0);
}

int are_flags_valid(char **av)
{
    if (valid_int_flag(av, 'x') != 0)
        return (1);
    if (valid_int_flag(av, 'y') != 0)
        return (1);
    if (search_flag_place(av, 'r') != -1 && valid_int_flag(av, 'r') != 0)
        return (1);
    return 0;
}

int error_handling_creator(char **av)
{
    if (all_flags_here(av) != 0) {
        printf("Some flags are missing. Please, refer to the help guide\n");
        return (1);
    }
    if (are_flags_valid(av) != 0) {
        printf(
            "One ore more flags are invalid. Please, refer to the help guide\n");
        return (1);
    }
    return (0);
}
