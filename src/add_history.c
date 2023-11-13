/*
** EPITECH PROJECT, 2023
** ADD_HISTORY
** File description:
** ADD_HISTORY
*/

#include "shell.h"
#include <stdlib.h>

void add_history(char *input, gll_t *env)
{
    char *hist_path = get_env(env, "HISTFILE");
    if (!hist_path) {
        free(hist_path);
        return;
    }
    FILE *fd = fopen(hist_path, "a");
    !fd ? perror("history") : 0;
    fprintf(fd, "%s", input);
    fclose(fd);
    free(hist_path);
}
