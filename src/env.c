/*
** EPITECH PROJECT, 2023
** SH_SET_ENV
** File description:
** Set self env setup
*/

#include "shell.h"
#include "gll.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

gll_t *sh_create_env(char **r_env)
{
    if (!r_env) return gll_init();
    char **tmp_env = dup_strtab(r_env);
    gll_t *env = array_to_gll(tmp_env);
    char *user = get_env(env, "USER");
    if (!user) return env;
    char *history = malloc(sizeof(char) * (my_strlen(user) + 22));
    if (!history) perror("malloc");
    strcpy(history, "/home/");
    strcat(history, user);
    strcat(history, "/.42sh_history");
    set_env(env, "HISTFILE", history);
    FILE *hist_file = fopen(history, "r");
    if (!hist_file) fclose(fopen(history, "w"));
    free(user);
    free(history);
    if (!get_env(env, "PATH")) gll_push_back(env, "PATH=/usr/bin:/bin");
    return env;
}

char *create_entry(char *key, char *value)
{
    int nb_alloc = my_strlen(key) + my_strlen(value) + 2;
    char *new = malloc(sizeof(char) * nb_alloc);
    strcpy(new, key);
    strcat(new, "=");
    strcat(new, value);
    return new;
}

gll_t *sh_update_env(char *key, char *value, gll_t *env)
{
    gll_node_t *current = env->first;
    while (current) {
        if (is_exist(current->data, key)) {
            free(current->data);
            int alloc_nb = (my_strlen(key) + my_strlen(value) + 2);
            current->data = malloc(sizeof(char) * alloc_nb);
            my_strcpy(current->data, create_entry(key, value));
            return env;
        }
        current = current->next;
    }
    gll_push_back(env, create_entry(key, value));
    return env;
}
