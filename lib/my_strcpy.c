/*
** EPITECH PROJECT, 2022
** MY_STRCPY
** File description:
** Copy src to dest.
*/

char *my_strcpy(char *dest, char const *src)
{
    int i;
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
