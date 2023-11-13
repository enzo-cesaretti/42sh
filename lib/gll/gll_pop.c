/*
** EPITECH PROJECT, 2023
** GLL
** File description:
** GLL_POP
*/

#include "gll.h"
#include <stddef.h>

void *gll_pop(gll_t *list)
{
    if (!list)
        return NULL;
    gll_node_t *node = list->first;
    if (node == NULL)
        return NULL;
    void *data = node->data;
    if (gll_remove(list, 0) == NULL)
        return NULL;
    return data;
}

void *gll_pop_back(gll_t *list)
{
    gll_node_t *node = list->last;
    if (node == NULL)
        return NULL;
    void *data = node->data;
    if (gll_remove(list, (list->size - 1)) == NULL)
        return NULL;
    return data;
}
