/*
** EPITECH PROJECT, 2023
** EXECUTE_PIPE
** File description:
** EXECUTE_PIPE
*/

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

int sh_num_builtins(void)
{
    char *builtin_str[] = {"cd", "help", "env", "setenv", "unsetenv",
    "history", "exit"};
    return sizeof(builtin_str) / sizeof(char *);
}

bool sh_is_builtins(char *build)
{
    char *clean_build = my_strdup(build);
    clean_build = trim(clean_build);
    char *builtin_str[] = {"cd", "help", "env", "setenv",
    "unsetenv", "history", "exit", NULL};
    for (int i = 0; builtin_str[i]; i++) {
        if (my_strcmp(clean_build, builtin_str[i])) {
            free(clean_build);
            return true;
        }
    }
    free(clean_build);
    return false;
}

int sh_launch(shell_t *sh, char **args)
{
    int pid, status = 1;
    pid = fork();
    if (pid == 0) {
        char *r_cmd = find_cmd(args[0], sh->env);
        if (r_cmd && dir_err(r_cmd, args)) exit(1);
        if (execve(r_cmd, args, gll_to_array(sh->env)) == -1) {
            my_puterr(args[0]);
            my_puterr(": Command not found.\n");
        }
        free(r_cmd);
        exit(1);
    } else if (pid < 0) {
        perror("fork");
    } else {
        wait(&status);
        handle_signal(status);
        sh->exit_status = WEXITSTATUS(status);
    }
    return 1;
}

int sh_execute(shell_t *sh, char **args)
{
    char *builtin_str[] = {"cd", "help", "env", "setenv", "unsetenv",
    "history", "exit"};
    int (*builtin_func[])(char **, gll_t *) = {
        &sh_cd, &sh_help, &sh_env, &sh_setenv, &sh_unsetenv, &history, &sh_exit
    };
    if (!args[0]) {
        sh->exit_status = 1;
        return 1;
    }
    for (int i = 0; i < sh_num_builtins(); i++)
        if (my_strcmp(args[0], builtin_str[i]))
            return (*builtin_func[i])(args, sh->env);
    return sh_launch(sh, args);
}

int sh_execute_builtin(shell_t *sh, char **args)
{
    char *builtin_str[] = {"cd", "help", "env", "setenv", "unsetenv",
    "hisrory", "exit"};
    int (*builtin_func[])(char **, gll_t *) = {
        &sh_cd, &sh_help, &sh_env, &sh_setenv, &sh_unsetenv, &history, &sh_exit
    };
    if (!args[0]) {
        sh->exit_status = 1;
        return 1;
    }
    for (int i = 0; i < sh_num_builtins(); i++)
        if (my_strcmp(trim(args[0]), builtin_str[i]))
            return (*builtin_func[i])(args, sh->env);
    return 1;
}
