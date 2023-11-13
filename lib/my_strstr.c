/*
** EPITECH PROJECT, 2023
** MY_STRSTR
** File description:
** strstr implementation
*/

#include "shell.h"

char *my_strstr(char *haystack, char *needle)
{
    int n = my_strlen(haystack);
    int m = my_strlen(needle);
    int j;
    for (int i = 0; i <= n - m; i++) {
        j = 0;
        while (j < m && haystack[i + j] == needle[j]) {
            j++;
        }
        if (j == m)
            return &haystack[i];
    }
    return NULL;
}
