/*
** EPITECH PROJECT, 2023
** CHECK_REDIRECTION
** File description:
** CHECK_REDIRECTION
*/

#include "shell.h"
#include <stdio.h>
#include <string.h>

int is_valid_pipe_command(char *cmd)
{
    int len_args = 0;
    char **args = sh_parser(my_strdup(cmd), " ");
    bool start = my_strcmp(args[0], "|");
    for (int i = 0; args[i]; i++) len_args++;
    bool end = my_strcmp(args[len_args - 1], "|");
    free_strtab(args);
    return start || end;
}

int is_valid_redir_command(char *cmd)
{
    int len_args = 0;
    char **args = sh_parser(my_strdup(cmd), " ");
    bool start = my_strcmp(args[0], ">");
    for (int i = 0; args[i]; i++) len_args++;
    bool end = my_strcmp(args[len_args - 1], ">");
    free_strtab(args);
    return start || end;
}
