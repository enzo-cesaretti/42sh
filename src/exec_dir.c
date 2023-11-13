/*
** EPITECH PROJECT, 2023
** EXEC_DIR
** File description:
** EXEC_DIR
*/

#include "shell.h"

bool dir_err(const char *filepath, char **args)
{
    if (!is_file(filepath)) {
        my_puterr(args[0]);
        my_puterr(": Permission denied.\n");
        return true;
    }
    return false;
}
