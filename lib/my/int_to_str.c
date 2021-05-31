/*
** EPITECH PROJECT, 2020
** int_to_str.c
** File description:
** this is the file to transform a int to a string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_revstr(char *str);

char *int_to_str(int nb, char *str)
{
    int nb_cpy = nb;
    int i = 0;

    if (nb < 0)
        nb *= -1;
    for (; nb != 0; i++) {
        str[i] = nb % 10 + '0';
        nb /= 10;
    }
    if (nb_cpy < 0) {
        str[i] = '-';
        i++;
    }
    str[i] = '\0';
    my_revstr(str);
    return (str);
}