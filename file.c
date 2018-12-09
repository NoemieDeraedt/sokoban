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

int count_x(char * buffer)
{
    int i;
    int o = 0;

    for (i = 0; buffer[i]; i++) {
        if (buffer[i] == 'X')
            o++;
    }
    return o;
}
