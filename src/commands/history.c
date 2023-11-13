/*
** EPITECH PROJECT, 2023
** HISTORY
** File description:
** HISTORY
*/

#include "shell.h"
#include "gll.h"
#include <stdio.h>
#include <stdlib.h>

int history_clear(char **args, gll_t *env)
{
    (void)args;
    char *hist_path = get_env(env, "HISTFILE");
    if (!hist_path) {
        free(hist_path);
        return 1;
    }
    FILE *fd = fopen(hist_path, "w");
    !fd ? perror("history") : 0;
    free(hist_path);
    fclose(fd);
    return 1;
}

int history(char **args, gll_t *env)
{
    (void)env;
    if (!args[1]) {
        char *hist_path = get_env(env, "HISTFILE");
        FILE *fd = fopen(hist_path, "r");
        !fd ? perror("history") : 0;
        free(hist_path);
        char *buff = NULL;
        size_t len = 0;
        while (getline(&buff, &len, fd) != -1)
            my_printf("%s", buff);
        free(buff);
        fclose(fd);
        return 1;
    }
    int (*history_func[])(char **, gll_t *) = {&history_clear, NULL};
    char *flags[] = {"-c", NULL};
    for (int i = 0, j = 1; flags[i]; i++, j++)
        if (my_strcmp(args[j], flags[i]))
            return history_func[i](args, env);
    return 1;
}
