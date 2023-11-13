/*
** EPITECH PROJECT, 2022
** MY_STRCOMP
** File description:
** Check if s1 is greater, equal or less than s2
*/

#include "shell.h"
#include <stdbool.h>

bool my_strcmp(char const *s1, char const *s2)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    if (len1 != len2) return false;
    for (int i = 0; s1[i] != '\0'; i++)
        if (s1[i] != s2[i]) return false;
    return true;
}
