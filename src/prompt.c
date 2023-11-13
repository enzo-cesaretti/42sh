/*
** EPITECH PROJECT, 2023
** B-PSU-200-MLN-2-1-minishell2-louis.chedru
** File description:
** prompt
*/

#include "shell.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char *get_currdir(void)
{
    char buff[4096];
    for (int i = 0 ; i < 4096 ; i++) buff[i] = '\0';
    char *cwd = getcwd(buff, 4096);
    char *token = strtok(cwd, "/");
    char *final = NULL;
    while (token) {
        final = my_strdup(token);
        token = strtok(NULL, "/");
    }
    return final;
}

void print_prompt(shell_t *sh)
{
    char *user = get_env(sh->env, "USER");
    if (!user) user = my_strdup("");
    char *hostname = get_env(sh->env, "HOSTNAME");
    if (!hostname) hostname = my_strdup("");
    my_printf("╭─\x1B[35m\e[1m\e[3m");
    my_printf("[%d]%s@%s", sh->exit_status, user, hostname);
    my_printf("\e[0m\x1B[0m \x1B[34m❯ \e[0m");
    my_printf("\e[1m\x1B[34m");
    my_printf(get_currdir());
    my_printf(" \e[0m\n╰─➤ ");
    my_putstr((!sh->hist_cmd) ? "" : sh->hist_cmd);
    free(user);
    free(hostname);
}
