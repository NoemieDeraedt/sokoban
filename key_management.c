/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** key_management.c
*/

#include "include/my.h"

char *right(char *buffer, state *var)
{
    if (buffer[var->p + 1] == 'X' && buffer[var->p + 2] != '#')
        my_swap(&buffer[var->p + 1], &buffer[var->p + 2]);
    if ((buffer[var->p + 2] != '#' && buffer[var->p + 1] == 'X'
        && buffer[var->p + 2] != 'X') || buffer[var->p + 1] == ' ')
        my_swap(&buffer[var->p], &buffer[var->p + 1]);
    if (buffer[var->p + 1] == 'O') {
        my_swap(&buffer[var->p + 1], &buffer[var->p]);
        buffer[var->p] = ' ';
        var->win++;
    }
    return buffer;
}

char *left(char *buffer, state *var)
{
    if (buffer[var->p - 1] == 'X' && buffer[var->p - 2] != '#')
        my_swap(&buffer[var->p - 1], &buffer[var->p - 2]);
    if ((buffer[var->p - 2] != '#' && buffer[var->p - 1] == 'X'
        && buffer[var->p - 2] != 'X') || buffer[var->p - 1] == ' ')
        my_swap(&buffer[var->p - 1], &buffer[var->p]);
    if (buffer[var->p - 1] == 'O') {
        my_swap(&buffer[var->p - 1], &buffer[var->p]);
        buffer[var->p] = ' ';
        var->win++;
    }
    return buffer;
}

char *up(char *buffer, state *var)
{
    if (buffer[var->p - var->columns] == 'X'
        && buffer[var->p - var->columns * 2] != '#')
        my_swap(&buffer[var->p - var->columns],
            &buffer[var->p - var->columns * 2]);
    if ((buffer[var->p - var->columns * 2] != '#'
        && buffer[var->p - var->columns] == 'X'
        && buffer[var->p - var->columns] != 'X')
        || buffer[var->p - var->columns] == ' ')
        my_swap(&buffer[var->p], &buffer[var->p - var->columns]);
    if (buffer[var->p - var->columns] == 'O') {
        my_swap(&buffer[var->p - var->columns], &buffer[var->p]);
        buffer[var->p] = ' ';
        var->win++;
    }
    return buffer;
}

char *down(char *buffer, state *var)
{
    if (buffer[var->p + var->columns] == 'X'
        && buffer[var->p + var->columns * 2] != '#')
        my_swap(&buffer[var->p + var->columns],
            &buffer[var->p + var->columns * 2]);
    if ((buffer[var->p + var->columns * 2] != '#'
        && buffer[var->p + var->columns] == 'X'
        && buffer[var->p + var->columns * 2] != 'X')
        || buffer[var->p + var->columns] == ' ')
        my_swap(&buffer[var->p], &buffer[var->p + var->columns]);
    if (buffer[var->p + var->columns] == 'O') {
        my_swap(&buffer[var->p + var->columns], &buffer[var->p]);
        buffer[var->p] = ' ';
        var->win++;
    }
    return buffer;
}

void conditions(char *buffer, int t, state *var)
{
    if (t == 67 && buffer[var->p + 1] != '#' && buffer[var->p + 1] != 'O')
        buffer = right(buffer, var);
    if (t == 68 && buffer[var->p - 1] != '#' && buffer[var->p - 1] != 'O')
        buffer = left(buffer, var);
    if (t == 65 && buffer[var->p - var->columns] != '#'
        && buffer[var->p - var->columns] != 'O')
        buffer = up(buffer, var);
    if (t == 66 && buffer[var->p + var->columns] != '#'
        && buffer[var->p + var->columns] != 'O')
        buffer = down(buffer, var);
    var->p = detect_p(buffer);
    var->lose = detect_lose(buffer);
}
