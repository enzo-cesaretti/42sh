/*
** EPITECH PROJECT, 2023
** ERROR
** File description:
** ERROR
*/

#include "shell.h"

bool pipe_syntaxe_error(char *tokens)
{
    if (is_valid_pipe_command(tokens)) {
        my_puterr("Invalid null command.\n");
        return true;
    }
    return false;
}

bool redir_syntaxe_error(char *tokens)
{
    if (is_valid_redir_command(tokens)) {
        my_puterr("Missing name for redirect.\n");
        return true;
    }
    return false;
}
