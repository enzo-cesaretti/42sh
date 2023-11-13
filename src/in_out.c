/*
** EPITECH PROJECT, 2023
** IN_OUT
** File description:
** INT_OUT
*/

#include "shell.h"
#include <fcntl.h>
#include <unistd.h>

void redirect_in(char *filename)
{
    int in = open(filename, O_RDONLY);
    dup2(in, STDIN_FILENO);
    close(in);
}

void redirect_out(char *filename)
{
    int out = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0666);
    dup2(out, STDOUT_FILENO);
    close(out);
}

void double_redirect_out(char *filename)
{
    int out = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0666);
    dup2(out, STDOUT_FILENO);
    close(out);
}
