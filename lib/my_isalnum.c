/*
** EPITECH PROJECT, 2023
** MY_ISALNUM
** File description:
** check alnum
*/

#include <stdbool.h>

bool my_isalnum(char c)
{
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9')) {
        return true;
    }
    return false;
}
