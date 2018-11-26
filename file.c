/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** file.c
*/

#include "include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ncurses.h>

char *inside_file(char const *file_path)
{
    int fd;
    char *buff = malloc(10000);

    fd = open(file_path, O_RDONLY);
    if (fd == -1)
        return ("ERROR");
    close(fd);
    free(buff);
    return (buff);
}

int my_sokoban(char *buffer)
{
    WINDOW *window;
    int sp;

    printw("%s", buffer);
    initscr();
    while (1) {
        clear();
        printw("hello %s", buffer);
        refresh();
        sp = getch();
        if (sp == 32)
            return (0);
    }
    endwin();
    free(window);
    return (0);
}
