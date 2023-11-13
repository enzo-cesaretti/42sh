/*
** EPITECH PROJECT, 2023
** SH_PARSE
** File description:
** Parse intput of the shell
*/

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **sh_parser(char *input, char *sep)
{
    int i, nb_toks = 1;
    for (int i = 0; input[i] != '\0'; i++)
        for (int j = 0; sep[j] != '\0'; j++)
            (input[i] == sep[j]) ? nb_toks++ : 0;
    char **toks = malloc(sizeof(char *) * (nb_toks + 1));
    if (!toks) return NULL;
    char *token = strtok(input, sep);
    for (i = 0; token; i++) {
        toks[i] = malloc(sizeof(char) * (my_strlen(token) + 1));
        if (!toks[i]) return NULL;
        my_strcpy(toks[i], token);
        token = strtok(NULL, sep);
    }
    toks[i] = NULL;
    return toks;
}
