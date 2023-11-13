/*
** EPITECH PROJECT, 2023
** SH
** File description:
** SH body
*/

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

char **select_redir(char *cmd)
{
    char *clean_cmd = tokenize(cmd);
    if (my_strstr(clean_cmd, " >  > ")) {
        char **redir = sh_parser(clean_cmd, ">");
        return double_redirection_right_out(redir);
    }
    if (my_strstr(clean_cmd, " > ")) {
        char **redir = sh_parser(clean_cmd, ">");
        return simple_redirection_right_out(redir);
    }
    if (my_strstr(clean_cmd, " < ")) {
        char **redir = sh_parser(clean_cmd, "<");
        return simple_redirection_right_in(redir);
    }
    return sh_parser(cmd, STRTOK_DELIM);
}

int handle_cmd(shell_t *sh)
{
    int status = 1;
    int my_stdout = dup(STDOUT_FILENO);
    int my_stdin = dup(STDIN_FILENO);
    if (my_stdout == -1 || my_stdout == -1) perror("DUP");
    if (pipe_syntaxe_error(sh->tokens)) return 1;
    if (redir_syntaxe_error(sh->tokens)) return 1;
    if (my_strstr(sh->tokens, "|")) {
        char **cmds = sh_parser(sh->tokens, "|");
        status = sh_pipe_exec(sh, cmds, my_stdin, 0);
        free_strtab(cmds);
    } else {
        char **args = select_redir(sh->tokens);
        status = sh_execute(sh, args);
        free_strtab(args);
    }
    int ret_out = dup2(my_stdout, STDOUT_FILENO);
    int ret_int = dup2(my_stdin, STDIN_FILENO);
    if (ret_out == -1 || ret_int == -1) perror("DUP 2");
    return status;
}

int handle_semicolone(shell_t *sh)
{
    int status = 1;
    char **all_args = sh_parser(sh->input, ";\n");
    for (int i = 0; all_args[i] && status; i++) {
        sh->tokens = all_args[i];
        status = handle_andor(sh);
    }
    free_strtab(all_args);
    return status;
}

char *concat(char *str, char *suffix)
{
    char *result = malloc(sizeof(char) *
    (strlen(str) + strlen(suffix) + 1));
    strcpy(result, str);
    strcat(result, suffix);
    return result;
}

void sh_loop(char **r_env)
{
    shell_t *sh = malloc(sizeof(shell_t));
    size_t n = 0;
    sh->input = NULL;
    sh->hist_cmd = NULL;
    sh->env = sh_create_env(r_env);
    int status = 1;
    do {
        if (isatty(STDIN_FILENO))
            print_prompt(sh);
        if (getline(&sh->input, &n, stdin) == -1) {
            gll_destroy(sh->env);
            free(sh);
            exit(0);
        }
        if (handle_history(sh)) continue;
        add_history(sh->input, sh->env);
        status = handle_semicolone(sh);
    } while (status);

}
