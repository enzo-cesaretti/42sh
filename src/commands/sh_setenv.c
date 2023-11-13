/*
** EPITECH PROJECT, 2023
** SH_SETENV
** File description:
** BUILTIN COMMAND
*/

#include "shell.h"

int sh_setenv(char **args, gll_t *env)
{
    if (!args[1]) {
        gll_node_t *current = env->first;
        for (; current; current = current->next)
            my_printf("%s\n", current->data);
        return 1;
    }
    if (check_value(args[1])) return 1;
    if (!args[2])
        env = sh_update_env(args[1], "", env);
    else
        env = sh_update_env(args[1], args[2], env);
    return 1;
}
