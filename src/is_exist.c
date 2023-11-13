/*
** EPITECH PROJECT, 2023
** IS_EXIST
** File description:
** Check if key exist in entry
*/

#include "shell.h"
#include <stdlib.h>

bool is_exist(char *entry, char *key)
{
    int var_len;
    for (var_len = 0; entry[var_len] != '='; var_len++);
    if (my_strlen(key) > var_len) return false;
    for (int i = 0; i < var_len; i++)
        if (!(entry[i] == key[i])) return false;
    return true;
}
