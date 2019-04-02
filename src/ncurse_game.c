/*
** EPITECH PROJECT, 2023
** game_of_life
** File description:
** Created by Anthony Anicotte,
*/
#include <stdlib.h>
#include <ncurses.h>
#include <zconf.h>
#include "struct.h"
#include "function.h"

int get_nbr_neighbors(game_of_life_t *gol_struct, int i, int j)
{
    int nbr_alive = 0;

    if (gol_struct->map[i - 1][j - 1] == '.')
        nbr_alive++;
    if (gol_struct->map[i - 1][j] == '.')
        nbr_alive++;
    if (gol_struct->map[i - 1][j + 1] == '.')
        nbr_alive++;
    if (gol_struct->map[i][j - 1] == '.')
        nbr_alive++;
    if (gol_struct->map[i][j + 1] == '.')
        nbr_alive++;
    if (gol_struct->map[i + 1][j - 1] == '.')
        nbr_alive++;
    if (gol_struct->map[i + 1][j] == '.')
        nbr_alive++;
    if (gol_struct->map[i + 1][j + 1] == '.')
        nbr_alive++;
    return (nbr_alive);
}

void cell_operation(game_of_life_t *gol_struct, int i, int j, char **tab)
{
    int nbr_neighbors_alive;

    if (gol_struct->map[i][j] == '-' || gol_struct->map[i][j] == '|')
        return;
    nbr_neighbors_alive = get_nbr_neighbors(gol_struct, i, j);
    if (gol_struct->map[i][j] == '.') {
        if (nbr_neighbors_alive < 2 || nbr_neighbors_alive > 3)
            tab[i][j] = ' ';
    } else if (gol_struct->map[i][j] == ' ')
        if (nbr_neighbors_alive == 3)
            tab[i][j] = '.';
}

void update_cells(game_of_life_t *gol_struct)
{
    char **tab = copy_tab(gol_struct->map, gol_struct->lines);

    for (int i = 0; gol_struct->map[i] != NULL; i++) {
        for (int j = 0; gol_struct->map[i][j] != '\0'; j++)
            cell_operation(gol_struct, i, j, tab);
    }
    free_tab(gol_struct->map);
    gol_struct->map = copy_tab(tab, gol_struct->lines);
    free_tab(tab);
    gol_struct->generation++;
    clear_print_and_refresh(gol_struct);
}

int get_event(game_of_life_t *gol_struct)
{
    while (1) {
        switch (getch()) {
        case KEY_BACKSPACE:
            return (0);
        case ' ':
            update_cells(gol_struct);
            break;
        }
    }
}

int start_game(game_of_life_t *gol_struct)
{
    initscr();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    noecho();
    print_tab(gol_struct->map, gol_struct->generation);
    refresh();
    clear_print_and_refresh(gol_struct);
    get_event(gol_struct);
    endwin();
    return (0);
}