/*
** EPITECH PROJECT, 2018
** int_to_char.c
** File description:
** int_to_char
*/

#include <stdlib.h>
#include "../../include/my.h"

char *int_to_char(int number)
{
    char *result;
    int divider = 10;
    int i;
    int result_modulo = 0;
    int j;
    int c = 0;
    int nb = number;

    do {
        c++;
    } while ((nb /= 10) > 0);
    result = malloc(c);
    for (i = c - 1; i >= 0; i--) {
        result_modulo = (number % divider - result_modulo) / (divider / 10);
        divider *= 10;
        result[i] = result_modulo + '0';
    }
    for (j = 0; result[j] == '\0'; j++) {
        result[j] = '~';
    }
    result = number_in_array(result, 1);
    return (result);
}
