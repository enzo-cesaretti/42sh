/*
** EPITECH PROJECT, 2023
** GETTER
** File description:
** get usefull var
*/

#include "shell.h"
#include "gll.h"
#include <stdlib.h>
#include <string.h>

char *is_empty_path(char *path)
{
    if (!path) return "";
    return my_strdup(path);
}

bool no_slash(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '/') return false;
    return true;
}

char *find_cmd(char *cmd, gll_t *env)
{
    if (no_slash(cmd)) {
        char *path = get_env(env, "PATH");
        if (!path) return cmd;
        char **path_tab = sh_parser(path, ":");
        if (!path_tab) return cmd;
        return search_cmd(path_tab, cmd);
    }
    return cmd;
}

char *get_env(gll_t *env, char *key)
{
    gll_node_t *current = env->first;
    while (current) {
        if (is_exist(current->data, key)) {
            char *path_string = my_strdup(current->data);
            char *path_var = strtok(path_string, "=");
            path_var = strtok(NULL, "=");
            return is_empty_path(path_var);
        }
        current = current->next;
    }
    return NULL;
}

void set_env(gll_t *env, char *key, char *value)
{
    gll_node_t *current = env->first;
    while (current) {
        if (is_exist(current->data, key)) {
            char *new_entry = malloc(sizeof(char) *
            (strlen(key) + strlen(value) + 2));
            strcpy(new_entry, key);
            strcat(new_entry, "=");
            strcat(new_entry, value);
            free(current->data);
            current->data = new_entry;
            return;
        }
        current = current->next;
    }
    char *new_entry = malloc(sizeof(char) *
    (strlen(key) + strlen(value) + 2));
    strcpy(new_entry, key);
    strcat(new_entry, "=");
    strcat(new_entry, value);
    gll_push(env, new_entry);
}
