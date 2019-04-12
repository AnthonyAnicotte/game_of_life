/*
** EPITECH PROJECT, 2023
** game_of_life
** File description:
** Created by Anthony Anicotte,
*/

#include <ncurses.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <getopt.h>
=======
>>>>>>> 5e33bf3a10b2592baa02a6cfce876027d2f68679
#include "struct.h"
#include "function_creator.h"

void delete_all_dots(creator_t *crea_struct)
{
    crea_struct->nbr_max_dot = 0;
    crea_struct->dot_pos_y = realloc(crea_struct->dot_pos_y,
        sizeof(int) * (crea_struct->nbr_max_dot + 1));
    crea_struct->dot_pos_x = realloc(crea_struct->dot_pos_x,
        sizeof(int) * (crea_struct->nbr_max_dot + 1));
    clear_print_and_refresh(crea_struct);
}

int get_event(creator_t *crea_struct)
{
    while (1) {
        switch (getch()) {
        case KEY_UP:
            key_up(crea_struct);
            break;
        case KEY_DOWN:
            key_down(crea_struct);
            break;
        case KEY_LEFT:
            key_left(crea_struct);
            break;
        case KEY_RIGHT:
            key_right(crea_struct);
            break;
        case ' ':
            space(crea_struct);
            break;
        case '\n':
            return (0);
        case 'r':
            delete_all_dots(crea_struct);
        case KEY_BACKSPACE:
            delete_all_dots(crea_struct);
<<<<<<< HEAD
        case 27:
            return (1);
=======
>>>>>>> 5e33bf3a10b2592baa02a6cfce876027d2f68679
        }
    }
}

int start_creator(creator_t *crea_struct, int ac, char **av)
{
    int leave = 0;

    if (flag_r_option(crea_struct, ac, av) == 0) {
        automatic_gen_map(crea_struct);
        return (0);
    }
    initscr();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    noecho();
    refresh();
    clear_print_and_refresh(crea_struct);
    if (get_event(crea_struct) == 1)
        leave = 1;
    endwin();
    return (leave);
}