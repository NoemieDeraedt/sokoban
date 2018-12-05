/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** sokobon.c
*/

#include "include/my.h"
#include <ncurses.h>

int detect_lose(char *buffer)
{
    int i;
    int error = 0;
    int x = count_x(buffer);
    int count = 0;

    for (i = 0; buffer[i]; i++) {
        if (buffer[i] == 'X') {
            error = count_error(buffer, i);
            if (error >= 2)
                count++;
        }
    }
    if (count == x)
        return 1;
    return 0;
}

int count_error(char *buffer, int i)
{
    int columns = count_columns(buffer);
    int error = 0;

    if (buffer[i + 1] == '#' || buffer[i + 1] == 'X')
        error++;
    if (buffer[i - 1] == '#' || buffer[i - 1] == 'X')
        error++;
    if (buffer[i + columns] == '#' || buffer[i + columns] == 'X')
        error++;
    if (buffer[i - columns] == '#' || buffer[i - columns] == 'X')
        error++;
    return error;
}

int detect_p(char *buffer)
{
    int i;

    for (i = 0; buffer[i]; i++) {
        if (buffer[i] == 'P')
            return (i);
    }
    return 84;
}

void open_window(char *buffer, state *var)
{
    int t;

    while (1) {
        if (var->win == var->o)
            break;
        clear();
        printw(buffer);
        refresh();
        t = getch();
        conditions(buffer, t, var);
        if (var->lose == 1)
            break;
        if (t == 32)
            break;
    }
}

int my_sokoban(char *buffer)
{
    int t;
    state var = init_vars(buffer);

    initscr();
    curs_set(FALSE);
    noecho();
    open_window(buffer, &var);
    clear();
    endwin();
    if (var.win == var.o)
        return 0;
    else if (var.lose == 1)
        return 1;
    return 2;
}
