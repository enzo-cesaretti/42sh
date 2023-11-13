/*
** EPITECH PROJECT, 2023
** FREE_STRTAB
** File description:
** FREE_STRTAB
*/

#include "shell.h"
#include <stdlib.h>

int print_strtab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        my_printf("%s\n", tab[i]);
    return 0;
}

int len_strtab(char **tab)
{
    int len = 0;
    for (; tab[len]; len++);
    return len;
}

char **dup_strtab(char **tab)
{
    int len = len_strtab(tab), i;
    char **new = malloc(sizeof(char *) * (len + 1));
    for (i = 0; tab[i]; i++)
        new[i] = my_strdup(tab[i]);
    new[i] = NULL;
    return new;
}

void free_strtab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}
