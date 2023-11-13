/*
** EPITECH PROJECT, 2023
** IS
** File description:
** IS
*/

int my_isspace(int c)
{
    return (c == ' ' || c == '\t' ||
    c == '\n' || c == '\r' ||
    c == '\f' || c == '\v');
}

int my_isalpha(int c)
{
    return ((c >= 'A' && c <= 'Z')
    || (c >= 'a' && c <= 'z'));
}
