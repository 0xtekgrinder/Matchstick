/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** task05
*/

#include <stddef.h>

int my_strlen(char const *str);

char *my_strstr(char *str, char const *to_find)
{
    int y = 0;
    int i = 0;
    int p = 0;
    int nb1 = my_strlen(str);
    int nb2 = my_strlen(to_find);

    while (p < nb1) {
        for (y = p; y < nb1 && str[y] != to_find[0]; y++);
        for (i = 0; str[i + y] == to_find[i] && i < nb2; i++);
        if (i == nb2)
            break;
        else
            p++;
    }
    if (p != nb1)
        return (&str[y]);
    else
        return (NULL);
}
