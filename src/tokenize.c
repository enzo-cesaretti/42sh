/*
** EPITECH PROJECT, 2023
** TOKENIZE
** File description:
** TOKENIZE
*/

#include "shell.h"
#include <stdlib.h>
#include <ctype.h>

char *tokenize(char *input)
{
    int j = 0, nb = 0;
    for (int i = 0; input[i] != '\0'; i++)
        if (input[i] == '<' || input[i] == '>' || input[i] == '|')
            nb++;
    char *clean_input = malloc(sizeof(char) * (my_strlen(input) + nb * 2 + 1));
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] != '>' && input[i] != '<' && input[i] != '|') {
            clean_input[j++] = input[i];
        } else {
            clean_input[j++] = ' ';
            clean_input[j++] = input[i];
            clean_input[j++] = ' ';
        }
    }
    clean_input[j++] = '\0';
    return clean_input;
}

char *ltrim(char *s)
{
    while (isspace(*s)) s++;
    return s;
}

char *rtrim(char *s)
{
    char *back = s + my_strlen(s);
    while (isspace(*--back));
    *(back + 1) = '\0';
    return s;
}

char *trim(char *s)
{
    return rtrim(ltrim(s));
}
