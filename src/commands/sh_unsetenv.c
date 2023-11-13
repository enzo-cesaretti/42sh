/*
** EPITECH PROJECT, 2023
** SH_UNSETENV
** File description:
** BUILTIN COMMAND
*/

#include "shell.h"

int sh_unsetenv(char **args, gll_t *env)
{
    if (!args[1]) {
        my_puterr("unsetenv: Too few arguments.\n");
        return 1;
    }
    gll_node_t *current = env->first;
    while (current) {
        if (is_exist(current->data, args[1])) {
            gll_unset(env, args[1]);
            return 1;
        }
        current = current->next;
    }
    return 1;
}
