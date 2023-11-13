/*
** EPITECH PROJECT, 2023
** HANDLE_HISTORY
** File description:
** HANDLE_HISTORY
*/

#include "shell.h"
#include <string.h>
#include <stdlib.h>

int handle_history(shell_t *sh)
{
    if (sh->input[0] == '!') {
        sh->input = sh->input + 1;
        sh->input[strlen(sh->input) - 1] = '\0';
        sh->hist_cmd = get_hist_line(sh, atoi(sh->input));
        sh->hist_cmd[strlen(sh->hist_cmd) - 1] = '\0';
        return 1;
    } else {
        if (sh->hist_cmd)
            sh->input = concat(sh->hist_cmd, sh->input);
        sh->hist_cmd = NULL;
        return 0;
    }
}
