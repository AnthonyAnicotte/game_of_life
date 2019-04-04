/*
** EPITECH PROJECT, 2023
** game_of_life
** File description:
** Created by Anthony Anicotte,
*/

#include "struct.h"
#include <ncurses.h>
#include <stdlib.h>
#include <memory.h>
#include "function_creator.h"

void print_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        printw("%s\n", tab[i]);
}

void update_map(creator_t *crea_struct)
{
    free_tab(crea_struct->dotty_map);
    crea_struct->dotty_map = malloc(sizeof(char *) * (crea_struct->lines + 3));
        for (int i = 0; crea_struct->empty_map[i] != NULL; i++)
            crea_struct->dotty_map[i] = strdup(crea_struct->empty_map[i]);
        crea_struct->dotty_map[crea_struct->lines + 2] = NULL;
    for (int i = 1; i <= crea_struct->nbr_max_dot; i++) {
        if (crea_struct->p_pos->x != crea_struct->dot_pos_x[i] ||
            crea_struct->p_pos->y != crea_struct->dot_pos_y[i])
            crea_struct->dotty_map[crea_struct->dot_pos_y[i]][crea_struct->dot_pos_x[i]] = '.';
    }
}

void print_if_a_dot_under(creator_t *crea_struct)
{
    printw("Dot under your character: ");
    if (there_is_a_dot_under_the_guy(crea_struct) == -1)
        printw("NO\n");
    else
        printw("YES\n");
}

void print_nbr_dots(creator_t *crea_struct)
{
    printw("%d dots have been placed", crea_struct->nbr_max_dot);
}

void print_cmds(void)
{
    printw("\n\n\nCommands:\n\n- Arrow keys to move your character\n- Space to place");
    printw("/remove a dot\n- Key R or BackSpace to reset the map\n- Enter to ");
    printw("save the map\n");
}

void clear_print_and_refresh(creator_t *crea_struct)
{
    clear();
    update_map(crea_struct);
    print_tab(crea_struct->dotty_map);
    print_if_a_dot_under(crea_struct);
    print_nbr_dots(crea_struct);
    print_cmds();
    refresh();
}