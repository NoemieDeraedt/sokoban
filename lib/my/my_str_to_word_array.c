/*
** EPITECH PROJECT, 2018
** my_str_to_word_array.c
** File description:
** task04
*/

#include <stdlib.h>

char **my_str_to_word_array(char const *str)
{
    char **array;
    int i = 0;
    int j = 0;
    int k = 0;

    while (str[i]) {
        while ((48 <= str[i] && 57 >= str[i]) || (65 <= str[i] && 90 >= str[i])
               || (97 <= str[i] && str[i] <= 122)) {
            array = malloc(i + 1);
            array[j] = malloc(k + 1);
            array[j][k] = str[i];
            i++;
            k++;
        }
        k = 0;
        j++;
        i++;
    }
    return (array);
}
