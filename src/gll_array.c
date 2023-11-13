/*
** EPITECH PROJECT, 2023
** GLL_TO_ARRAY
** File description:
** gll_to_array
*/

#include "shell.h"
#include "gll.h"
#include <stdlib.h>

char **gll_to_array(gll_t *list)
{
    int len, i;
    gll_node_t *current = list->first;
    for (len = 0; current; len++)
        current = current->next;
    char **array = malloc(sizeof(char *) * (len + 1));
    if (!array) return NULL;
    current = list->first;
    for (i = 0; current; i++) {
        array[i] = malloc(sizeof(char) * (my_strlen(current->data) + 1));
        if (!array[i]) return NULL;
        my_strcpy(array[i], current->data);
        current = current->next;
    }
    array[i] = NULL;
    return array;
}

gll_t *array_to_gll(char **array)
{
    int len;
    for (len = 0; array[len]; len++);
    gll_t *list = gll_init();
    for (int i = len - 1; i >= 0; i--)
        gll_push(list, array[i]);
    return list;
}

void gll_unset(gll_t *list, char *key)
{
    gll_node_t *current = list->first;
    gll_node_t *prev, *tmp;
    if (current && is_exist(current->data, key)) {
        tmp = list->first;
        list->first = current->next;
        free(tmp->data);
        free(tmp);
        return;
    }
    while (current && !is_exist(current->data, key)) {
        prev = current;
        current = current->next;
    }
    if (!current) return;
    prev->next = current->next;
    free(current);
}
