/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** init_structs.c
*/

#include "include/my.h"

void init_vars(state *var, char *buffer)
{
    var->win = 0;
    var->p = detect_p(buffer);
    var->columns = count_columns(buffer);
    var->o = count_o(buffer);
}

void initstruct(error *hashtags)
{
    hashtags->error_right = 0;
    hashtags->error_left = 0;
    hashtags->error_up = 0;
    hashtags->error_down = 0;
}
