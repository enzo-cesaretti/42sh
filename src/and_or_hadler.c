/*
** EPITECH PROJECT, 2023
** B-PSU-200-MLN-2-1-42sh-louis.chedru
** File description:
** and_or_hadler
*/

#include "shell.h"
#include "gll.h"
#include <stdlib.h>

int andor_error(void)
{
    my_puterr("Invalid null command.\n");
    return 1;
}

bool and_operator(shell_t *sh, bool v, andor_t *prev_type)
{
    if (v && prev_type->type == AND) {
        handle_cmd(sh);
        return true;
    }
    if (!v && prev_type->type == AND) return false;
    if (v) handle_cmd(sh);
    if (!v) return false;
    if (sh->exit_status == 0) return true;
    return false;
}

bool or_operator(shell_t *sh, bool v, andor_t *prev_type)
{
    if (!v && prev_type->type == OR_P) return true;
    if (v && prev_type->type == OR_P) {
        handle_cmd(sh);
        return false;
    }
    if (!v) {
        handle_cmd(sh);
        return sh->exit_status == 0;
    }
    if (v) return false;
    return false;
}

bool expression_value(shell_t *sh, bool v, gll_node_t *node)
{
    andor_t *cmd = node->data;
    sh->tokens = cmd->cmd;
    andor_t *prev_cmd = node->prev->data;
    andor_t tmp = {-1, NULL};
    andor_t *prev_type = (node->prev->prev) ? node->prev->prev->data : &tmp;
    if (prev_cmd->type == AND) return and_operator(sh, v, prev_type);
    if (prev_cmd->type == OR_P) return or_operator(sh, v, prev_type);
    return false;
}

int handle_andor(shell_t *sh)
{
    char *token = sh->tokens;
    gll_t *parsed = parse_andor(token);
    if (!parsed) return andor_error();
    if (parsed->size == 1) return handle_cmd(sh);
    gll_node_t *curr = parsed->first;
    andor_t *cmd = curr->data;
    sh->tokens = cmd->cmd;
    handle_cmd(sh);
    bool expr_res = expression_value(sh, (sh->exit_status == 0) ? true : false,
                                    curr->next);
    curr = curr->next->next;
    for (; curr; curr = curr->next) {
        expr_res = expression_value(sh, expr_res, curr);
        free(sh->tokens);
    }
    return 1;
}
