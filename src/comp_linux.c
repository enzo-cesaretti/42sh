/*
** EPITECH PROJECT, 2023
** COMP_LINUX
** File description:
** Check compilation
*/

#include "shell.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

bool comp_for_linux(char *filepath)
{
    struct stat st;
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) return NULL;
    stat(filepath, &st);
    char *buff = malloc(sizeof(char) * (st.st_size + 1));
    read(fd, buff, st.st_size);
    if (my_strstr(buff, "Linux") != NULL) {
        free(buff);
        return true;
    }
    free(buff);
    my_puterr(filepath);
    my_puterr(": Exec format error. Wrong Architecture.\n");
    return false;
}
