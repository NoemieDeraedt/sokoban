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

int count_o(char *buffer)
{
    int i;
    int o = 0;

    for (i = 0; buffer[i]; i++) {
        if (buffer[i] == 'O')
            o++;
    }
    return o;
}

int detect_loose(char *buffer)
{
    
    return 0;
}

int my_sokoban(char *buffer)
{
    int t;
    int p = detect_p(buffer);
    int columns = count_columns(buffer);
    int win = 0;
    int o = count_o(buffer);

    initscr();
    noecho();
    while (1) {
        if (win == o)
            break;
        clear();
        printw(buffer);
        refresh();
        t = getch();
        if (t == 32)
            return (0);
        if (t == 67 && buffer[p + 1] != '#' && buffer[p + 1] != 'O') {
            if (buffer[p + 1] == 'X' && buffer[p + 2] != '#')
                my_swap(&buffer[p + 1], &buffer[p + 2]);
            if ((buffer[p + 2] != '#' && buffer[p + 1] == 'X' && buffer[p + 2] != 'X') || buffer[p + 1] == ' ')
                my_swap(&buffer[p], &buffer[p + 1]);
            if (buffer[p + 1] == 'O') {
                my_swap(&buffer[p + 1], &buffer[p]);
                buffer[p] = ' ';
                win++;
            }
        }
        if (t == 68 && buffer[p - 1] != '#' && buffer[p - 1] != 'O') {
            if (buffer[p - 1] == 'X' && buffer[p - 2] != '#')
                my_swap(&buffer[p - 1], &buffer[p - 2]);
            if ((buffer[p - 2] != '#' && buffer[p - 1] == 'X' && buffer[p - 2] != 'X') || buffer[p - 1] == ' ')
                my_swap(&buffer[p - 1], &buffer[p]);
            if (buffer[p - 1] == 'O') {
                my_swap(&buffer[p - 1], &buffer[p]);
                buffer[p] = ' ';
                win++;
            }
        }
        if (t == 65 && buffer[p - columns] != '#' && buffer[p - columns] != 'O') {
            if (buffer[p - columns] == 'X' && buffer[p - columns * 2] != '#')
                my_swap(&buffer[p - columns], &buffer[p - columns * 2]);
            if ((buffer[p - columns * 2] != '#' && buffer[p - columns] == 'X' && buffer[p - columns] != 'X') || buffer[p - columns] == ' ')
                my_swap(&buffer[p], &buffer[p - columns]);
            if (buffer[p - columns] == 'O') {
                my_swap(&buffer[p - columns], &buffer[p]);
                buffer[p] = ' ';
                win++;
            }
        }
        if (t == 66 && buffer[p + columns] != '#' && buffer[p + columns] != 'O') {
            if (buffer[p + columns] == 'X' && buffer[p + columns * 2] != '#')
                my_swap(&buffer[p + columns], &buffer[p + columns * 2]);
            if ((buffer[p + columns * 2] != '#' && buffer[p + columns] == 'X' && buffer[p + columns * 2] != 'X') || buffer[p + columns] == ' ')
                my_swap(&buffer[p], &buffer[p + columns]);
            if (buffer[p + columns] == 'O') {
                my_swap(&buffer[p + columns], &buffer[p]);
                buffer[p] = ' ';
                win++;
            }
        }
        p = detect_p(buffer);
        if (detect_loose(buffer) == 1)
            break;
    }
    clear();
    endwin();
    if (win == o)
        return 0;
    return 1;
}
