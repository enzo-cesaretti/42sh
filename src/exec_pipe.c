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

void dup_for_child(char **args, int pipe_fd[2], int fd, int idx)
{
    dup2(fd, STDIN_FILENO);
    if (args[idx + 1])
        dup2(pipe_fd[1], STDOUT_FILENO);
    close(pipe_fd[0]);
}

int sh_pipe_launch(char **args, gll_t *env)
{
    char *r_cmd = find_cmd(args[0], env);
    if (r_cmd && dir_err(r_cmd, args)) exit(1);
    if (execve(r_cmd, args, gll_to_array(env)) == -1) {
        my_puterr(args[0]);
        my_puterr(": Command not found.\n");
    }
    free(r_cmd);
    return 1;
}

int sh_pipe_execute(shell_t *sh, char **args)
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
    return sh_pipe_launch(args, sh->env);
}

int exec_cmd(shell_t *sh, char **args, int idx)
{
    int status = 1;
    char **cmd = select_redir(args[idx]);
    status = sh_pipe_execute(sh, cmd);
    return status;
}

int sh_pipe_exec(shell_t *sh, char **args, int fd, int idx)
{
    if (!args[idx]) return 1;
    int pipe_fd[2], wstatus = 0, status = 1, pid;
    pipe(pipe_fd);
    if (sh_is_builtins(strtok(my_strdup(args[idx]), " ")) && !args[idx + 1]) {
        char **cmd_args = sh_parser(args[idx], STRTOK_DELIM);
        status = sh_execute_builtin(sh, cmd_args);
        free_strtab(cmd_args);
        status = sh_pipe_exec(sh, args, pipe_fd[0], idx + 1);
    } else {
        if ((pid = fork()) < 0) perror("fork");
        if (pid == 0) {
            dup_for_child(args, pipe_fd, fd, idx);
            status = exec_cmd(sh, args, idx);
            exit(1);
        } else {
            sh->exit_status = WEXITSTATUS(wait_child_death(wstatus, pipe_fd));
            status = sh_pipe_exec(sh, args, pipe_fd[0], idx + 1);
        }
    }
    return status;
}
