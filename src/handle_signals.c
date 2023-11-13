/*
** EPITECH PROJECT, 2023
** HANDLE_SIGNALS
** File description:
** Handle signals
*/

#include "shell.h"
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

void sig_err(int status)
{
    my_puterr("Segmentation fault");
    if (WCOREDUMP(status))
        my_puterr(" (core dumped)\n");
    else
        my_puterr("\n");
}

void fpe_err(int status)
{
    my_puterr("Floating exception");
    if (WCOREDUMP(status))
        my_puterr(" (core dumped)\n");
    else
        my_puterr("\n");
}

void handle_signal(int status)
{
    if (!WIFSIGNALED(status)) return;
    switch (WTERMSIG(status)) {
        case SIGSEGV:
            sig_err(status);
            break;
        case SIGFPE:
            fpe_err(status);
            break;
        default:
            break;
    }
}
