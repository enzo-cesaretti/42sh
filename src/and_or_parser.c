/*
** EPITECH PROJECT, 2023
** B-PSU-200-MLN-2-1-42sh-louis.chedru
** File description:
** and_or_parser
*/

#include "shell.h"
#include <string.h>
#include <stdlib.h>

char *strabdup(char *str, int a, int b)
{
    if (a >= (int)strlen(str)) return NULL;
    if (b >= (int)strlen(str) || b < 0) b = strlen(str) - 1;
    char *res = malloc(sizeof(char) * (b - a + 1));
    int k = 0;
    for (; a <= b; a++, k++)
        res[k] = str[a];
    res[k] = '\0';
    return res;
}

/* gll_t *parse_multiple_sep(char *str, char *seps)
{
    if (!seps) return NULL;
    gll_t *tokens = gll_init();
    char *sep_occurence = NULL;
    char *cpy = strdup(str);
    char *cpy2 = NULL;
    char *to_add = NULL;
    my_printf("%s\n", cpy);
    sep_occurence = strstr(cpy, seps);
    while (sep_occurence) {
        cpy2 = sep_occurence + strlen(seps);
        my_printf("%s\n", cpy2);
        to_add = strabdup(cpy, 0, sep_occurence - cpy - 1);
        gll_push_back(tokens, to_add);
        cpy = cpy2;
        sep_occurence = strstr(cpy, seps);
    }
    gll_push_back(tokens, strabdup(cpy, 0, sep_occurence - cpy - 1));
    return tokens;
}
 */
andor_t *init_andor(char *str, char *sep)
{
    andor_t *andor = malloc(sizeof(andor_t));
    if (strcmp(sep, "&&") == 0) andor->type = AND;
    else if (strcmp(sep, "||") == 0)  andor->type = OR_P;
    else
        andor->type = -1;
    andor->cmd = tokenize(strdup(str));
    return andor;
}

int find_first_sep(char *str)
{
    char *and_occurence = strstr(str, "&&");
    char *or_occurence = strstr(str, "||");
    int and_pos = (and_occurence) ? and_occurence - str : -1;
    int or_pos = (or_occurence) ? or_occurence - str : -1;
    if (and_pos == -1 && or_pos != -1) return OR_P;
    if (and_pos != -1 && or_pos == -1) return AND;
    if (and_pos != -1 && or_pos != -1)
        return (and_pos < or_pos) ? AND : OR_P;
    return -1;
}

gll_t *parse_andor(char *str)
{
    gll_t *tokens = gll_init();
    char *sep_occurence = NULL;
    char *cpy = strdup(str);
    char *cpy2 = NULL;
    char *to_add = NULL;
    char *seps = (find_first_sep(cpy) == AND) ? strdup("&&") : strdup("||");
    sep_occurence = strstr(cpy, seps);
    while (sep_occurence) {
        cpy2 = sep_occurence + strlen(seps);
        to_add = strabdup(cpy, 0, sep_occurence - cpy - 1);
        if (!to_add) return NULL;
        gll_push_back(tokens, init_andor(to_add, seps));
        cpy = cpy2;
        seps = (find_first_sep(cpy) == AND) ? strdup("&&") : strdup("||");
        sep_occurence = strstr(cpy, seps);
    }
    to_add = strabdup(cpy, 0, sep_occurence - cpy - 1);
    if (!to_add) return NULL;
    gll_push_back(tokens, init_andor(to_add, "none"));
    return tokens;
}
