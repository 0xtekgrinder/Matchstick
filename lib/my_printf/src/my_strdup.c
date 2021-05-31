/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** task01
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src)
{
    int nb = my_strlen(src);
    char *str = malloc(sizeof(char) * (nb + 1));

    my_strcpy(str, src);
    return (str);
}
