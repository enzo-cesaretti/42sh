/*
** EPITECH PROJECT, 2023
** SH_ENV
** File description:
** BUILTIN COMMAND
*/

#include "shell.h"

int sh_exit(char **args, gll_t *env)
{
    (void)args;
    (void)env;
    my_putstr("exit\n");
    return 0;
}
