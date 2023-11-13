/*
** EPITECH PROJECT, 2023
** MAIN
** File description:
** MAIN
*/

#include "shell.h"
#include <stdlib.h>

int main(int argc, char **argv, char **r_env)
{
    (void)argc;
    (void)argv;
    sh_loop(r_env);
    return 0;
}
