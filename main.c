/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** main.c
*/

#include "include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ncurses.h>

void rules(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    map  file representing the warehouse map, ");
    my_putstr("containing ‘#’ for walls, \n");
    my_putstr("         ‘P’ for the player, ‘X’ for boxes and ‘O’ ");
    my_putstr("for storage locations.\n");
}

int main(int argc, char **argv)
{
    char *buff;
    int result;

    if (argc == 1)
        return 84;
    if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
        rules();
        return (0);
    }
    buff = inside_file(argv[1]);

    //GESTION D'ERREUR
    if (error_verification(buff) == 84)
        return (84);

    result = my_sokoban(buff);
    if (result == 0)
        my_putstr("You win !\n");
    else if (result == 1)
        my_putstr("You lose !\n");
    free(buff);
    return 0;
}
