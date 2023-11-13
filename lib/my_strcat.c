/*
** EPITECH PROJECT, 2022
** MY_STRCAT
** File description:
** Concatenates two strings
*/

#include "shell.h"

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);
    for (int j = 0; src[j] != '\0'; j++, i++)
        dest[i] = src[j];
    dest[i] = '\0';
    return dest;
}
