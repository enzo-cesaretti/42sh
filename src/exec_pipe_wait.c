/*
** EPITECH PROJECT, 2023
** EXECUTE_PIPE_WAIT
** File description:
** EXECUTE_PIPE_WAIT
*/

#include "shell.h"
#include <sys/wait.h>
#include <unistd.h>

int wait_child_death(int wstatus, int pipe_fd[2])
{
    wait(&wstatus);
    handle_signal(wstatus);
    close(pipe_fd[1]);
    return wstatus;
}
