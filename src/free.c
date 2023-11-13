/*
** EPITECH PROJECT, 2023
** FREE_ALL
** File description:
** FREE_ALL
*/

#include "shell.h"
#include <stdlib.h>

void free_all(char **args, char *tokens)
{
    free_strtab(args);
    free(tokens);
}
