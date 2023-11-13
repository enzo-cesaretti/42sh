/*
** EPITECH PROJECT, 2023
** CHECK_VALUE
** File description:
** check valid value
*/

#include "shell.h"
#include <stdbool.h>

bool check_value(char *key)
{
    if (!my_isalnum(key[0])) {
        my_puterr("setenv: Variable name must begin with a letter.\n");
        return true;
    }
    for (int i = 0; key[i] != '\0'; i++) {
        if (!my_isalnum(key[i])) {
            my_puterr("setenv: Variable name must contain ");
            my_puterr("alphanumeric characters.\n");
            return true;
        }
    }
    return false;
}
