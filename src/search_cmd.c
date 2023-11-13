/*
** EPITECH PROJECT, 2023
** SEARCH_CMD
** File description:
** Check if cmd is in filepath
*/

#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char *search_cmd(char **paths, char *cmd)
{
    char *possible_path;
    for (int i = 0; paths[i]; i++) {
        int alloc_space = strlen(paths[i]) + strlen(cmd);
        possible_path = malloc(sizeof(char) * (alloc_space + 2));
        strcpy(possible_path, paths[i]);
        strcat(possible_path, "/");
        strcat(possible_path, cmd);
        if (access(possible_path, F_OK | X_OK) == 0)
            return possible_path;
        free(possible_path);
    }
    return NULL;
}
