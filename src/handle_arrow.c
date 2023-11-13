/*
** EPITECH PROJECT, 2023
** HANDLE_ARROW
** File description:
** HANDLE_ARROW
*/

#include "shell.h"
#include <termios.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

void handle_arrow(char *input, gll_t *env)
{
    (void)env;
    if (strstr(input, "\e[D"))
        my_printf("UP\n");
}
