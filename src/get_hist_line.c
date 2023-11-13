/*
** EPITECH PROJECT, 2023
** GET_HIST_LINE
** File description:
** GET_HIST_LINE
*/

#include "shell.h"

char *get_hist_line(shell_t *sh, int line)
{
    if (line <= 0) return NULL;
    char *hist_path = get_env(sh->env, "HISTFILE");
    if (!hist_path) return NULL;
    FILE *file = fopen(hist_path, "r");
    if (!file) return NULL;
    char *buff = NULL;
    size_t n = 0;
    for (int i = 0; i < line && getline(&buff, &n, file) != -1; i++);
    return buff;
}
