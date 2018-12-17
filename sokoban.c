/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** sokobon.c
*/

#include "include/my.h"
#include <ncurses.h>
#include <stdlib.h>

int detect_lose(char *buffer)
{
    int i;
    int error;
    int x = count_x(buffer);
    int count = 0;

    for (i = 0; buffer[i]; i++) {
        if (buffer[i] == 'X') {
            error = count_error(buffer, i);
            if (error == 1)
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
    error hashtags;

    initstruct(&hashtags);
    if (buffer[i + 1] == '#' || buffer[i + 1] == 'X')
        hashtags.error_right++;
    if (buffer[i - 1] == '#' || buffer[i - 1] == 'X')
        hashtags.error_left++;
    if (buffer[i + columns] == '#' || buffer[i + columns] == 'X')
        hashtags.error_down++;
    if (buffer[i - columns] == '#' || buffer[i - columns] == 'X')
        hashtags.error_up++;
    if ((hashtags.error_right == 1 && hashtags.error_up == 1)
        || (hashtags.error_right  == 1 && hashtags.error_down == 1)
        || (hashtags.error_left == 1 && hashtags.error_up == 1)
        || (hashtags.error_left == 1 && hashtags.error_down == 1)) {
            return 1;
    }
    return 0;
}

int detect_p(char *buffer)
{
    int i;

    for (i = 0; buffer[i]; i++)
        if (buffer[i] == 'P')
            return (i);
    return 84;
}

void open_window(char *buffer, state *var, char *file_path)
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
        if (t == 32) {
            init_vars(var, buffer);
            buffer = inside_file(file_path);
        }
    }
}

int my_sokoban(char *buffer, char *file_path)
{
    state *var = malloc(sizeof(state));

    init_vars(var, buffer);
    initscr();
    curs_set(FALSE);
    noecho();
    open_window(buffer, var, file_path);
    clear();
    endwin();
    if (var->win == var->o)
        return 0;
    else if (var->lose == 1)
        return 1;
    return 2;
}
