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
    char *buff = malloc(1000);
    int fd;

    fd = open(file_path, O_RDONLY);
    if (fd == -1)
        return ("ERROR");
    read(fd, buff, 9999);
    close(fd);
    return buff;
}

int detect_p(char *buffer)
{
    int i;

    for (i = 0; buffer[i]; i++) {
        if (buffer[i] == 'P')
            return (i);
    }
    return 84;
}

int count_columns(char *buffer)
{
    int i;

    for (i = 0; buffer[i] != '\n'; i++);
    i++;
    return i;
}

int my_sokoban(char *buffer)
{
    int t;
    int p = detect_p(buffer);
    int columns = count_columns(buffer);

    initscr();
    noecho();
    while (1) {
        clear();
        printw(buffer);
        refresh();
        t = getch();
        if (t == 32)
            return (0);
        if (t == 67 && buffer[p + 1] != '#' && buffer[p + 1] != 'O') {
            if (buffer[p + 1] == 'X' && buffer[p + 2] != '#')
                my_swap(&buffer[p + 1], &buffer[p + 2]);
            my_swap(&buffer[p], &buffer[p + 1]);
        }
        if (t == 68 && buffer[p - 1] != '#' && buffer[p - 1] != 'O') {
            if (buffer[p - 1] == 'X' && buffer[p - 2] != '#')
                my_swap(&buffer[p - 1], &buffer[p - 2]);
            my_swap(&buffer[p - 1], &buffer[p]);
        }
        if (t == 65 && buffer[p - columns] != '#' && buffer[p - columns] != 'O') {
            if (buffer[p - columns] == 'X' && buffer[p - columns * 2] != '#')
                my_swap(&buffer[p - columns], &buffer[p - columns * 2]);
            my_swap(&buffer[p], &buffer[p - columns]);
        }
        if (t == 66 && buffer[p + columns] != '#' && buffer[p + columns] != 'O') {
            if (buffer[p + columns] == 'X' && buffer[p + columns * 2] != '#')
                my_swap(&buffer[p + columns], &buffer[p + columns * 2]);
            my_swap(&buffer[p], &buffer[p + columns]);
        }
        p = detect_p(buffer);
    }
    endwin();
    return (0);
}
