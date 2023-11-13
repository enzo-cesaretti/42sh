/*
** EPITECH PROJECT, 2023
** SH_HELP
** File description:
** BUITIN COMMAND
*/

#include "shell.h"

int sh_help(char **args, gll_t *env)
{
    (void)args;
    (void)env;
    int i;
    char *builtin_str[] = {"cd", "help", "env", "setenv", "unsetenv",
    "history", "exit"};
    my_printf("EPITECH 42sh\n\n");
    my_printf("Type program names and arguments, and hit enter.\n");
    my_printf("The following are built in:\n");
    for (i = 0; i < sh_num_builtins(); i++)
        my_printf("  %s\n", builtin_str[i]);
    my_printf("Use the man command for information on other programs.\n\n");
    my_printf("By:\n");
    my_printf(
        "  Enzo CESARETTI\n  Louis CHEDRU\n  Julien Roy\n  Andrée Stana\n\n");
    return 1;
}
