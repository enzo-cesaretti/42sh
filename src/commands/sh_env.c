/*
** EPITECH PROJECT, 2023
** SH_CD
** File description:
** BUILTIN COMMAND
*/

#include "shell.h"

int sh_env(char **args, gll_t *env)
{
    (void)args;
    gll_node_t *current = env->first;
    while (current) {
        my_printf("%s\n", current->data);
        current = current->next;
    }
    return 1;
}
