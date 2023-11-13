/*
** EPITECH PROJECT, 2023
** IS_DIR
** File description:
** IS_DIR
*/

#include "shell.h"
#include <dirent.h>
#include <errno.h>

int is_file(const char *dirpath)
{
    DIR *dir = opendir(dirpath);
    if (dir != NULL) {
        closedir(dir);
        return 0;
    }
    if (errno == ENOTDIR)
        return 1;
    return -1;
}
