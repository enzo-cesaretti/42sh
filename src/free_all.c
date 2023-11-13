/*
** EPITECH PROJECT, 2023
** FREE_ALL
** File description:
** FREE_ALL
*/

#include "shell.h"
#include <stdlib.h>

void free_sh(shell_t *sh)
{
    free(sh->input);
    gll_destroy(sh->env);
    free(sh);
}
