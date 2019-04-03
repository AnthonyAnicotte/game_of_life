/*
** EPITECH PROJECT, 2023
** game_of_life
** File description:
** Created by Anthony Anicotte,
*/

#include <ncurses.h>
#include "struct.h"
#include "function_creator.h"

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
        case KEY_BACKSPACE:
            return (0);
        }
    }
}

void start_creator(creator_t *crea_struct)
{
    initscr();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    noecho();
    refresh();
    clear_print_and_refresh(crea_struct);
    get_event(crea_struct);
    endwin();
}