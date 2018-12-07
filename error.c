/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** error_verification.c
*/

#include <stdio.h>

int error_verification(char *buffer)
{
    char buff;
    int i;

    for (i = 0; buffer[i]; i++) {
        buff = buffer[i];
        if (buff != '#' && buff != 'P' && buff != 'X' && buff != 'O'
            && buff != '\n' && buff != ' ' && buff != '\0')
            return (84);
    }
    return 0;
}
