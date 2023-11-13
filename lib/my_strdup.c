/*
** EPITECH PROJECT, 2023
** MY_STRDUP
** File description:
** Return a copy of the string in arg
*/

#include "shell.h"
#include <stdlib.h>

char *my_strdup(char *str)
{
    char *cpy = malloc(sizeof(char) * (my_strlen(str) + 1));
    my_strcpy(cpy, str);
    return cpy;
}
