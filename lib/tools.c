/*
** EPITECH PROJECT, 2023
** TOOLS
** File description:
** Usefull functions
*/

#include "shell.h"
#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
}

void my_put_nbr(int nb)
{
    if (nb >= 0 && nb < 10) my_putchar(nb + '0');
    else if (nb < 0) {
        my_putchar('-');
        my_put_nbr(nb * (-1));
    } else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
}

int my_strlen(const char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}

void my_puterr(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(2, &str[i], 1);
}
