/*
** EPITECH PROJECT, 2023
** REDIRECTIONS
** File description:
** REDIRECTIONS
*/

#include "shell.h"
#include <string.h>

char **double_redirection_right_out(char **redir)
{
    double_redirect_out(strtok(redir[2], STRTOK_DELIM));
    char *s_cmd = my_strdup(redir[0]);
    free_strtab(redir);
    return sh_parser(s_cmd, STRTOK_DELIM);
}

char **simple_redirection_right_out(char **redir)
{
    redirect_out(strtok(redir[1], STRTOK_DELIM));
    char *s_cmd = my_strdup(redir[0]);
    free_strtab(redir);
    return sh_parser(s_cmd, STRTOK_DELIM);
}

char **simple_redirection_right_in(char **redir)
{
    redirect_in(strtok(redir[1], STRTOK_DELIM));
    char *s_cmd = my_strdup(redir[0]);
    free_strtab(redir);
    return sh_parser(s_cmd, STRTOK_DELIM);
}
