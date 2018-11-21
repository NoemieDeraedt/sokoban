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

char *inside_file(char const *file_path)
{
    int i;
    int fd;
    char *buff = malloc(10000);
    int size;

    fd = open(file_path, O_RDONLY);
    if (fd == -1)
        return ("ERROR");
    size = read(fd, buff, 9999);
    close(fd);
    free(buff);
    return(buff);
}
