/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** main.c
*/

#include "include/my.h"

void rules(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    map  file representing the warehouse map, ");
    my_putstr("containing ‘#’ for walls,\n");
    my_putstr("         ‘P’ for the player, ‘X’ for boxes and ‘O’ ");
    my_putstr("for storage locations.\n");
}

int main(int argc, char **argv)
{
    char *buffer;
    int i;
    char buff;

    if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
        rules();
        return (0);
    }
    buffer = inside_file(argv[1]);

    //GESTION D'ERREUR
    if (error_verification(buffer) == 84)
        return (84);

    return 0;
}
