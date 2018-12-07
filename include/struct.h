/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** stuct.h
*/

typedef struct states {
    int win;
    int p;
    int columns;
    int o;
    int lose;
} state;

typedef struct error {
    int error_up;
    int error_down;
    int error_left;
    int error_right;
} error;
