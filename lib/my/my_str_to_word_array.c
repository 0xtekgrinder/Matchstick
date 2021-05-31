/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** task04
*/

#include <stdlib.h>

static int my_strlen(char const *str)
{
    int nb = 0;

    for (; str[nb] != '\0'; nb++);
    return (nb);
}

static int c_to_skip(char a)
{
    if (a != ':') {
        return (0);
    } else {
        return (1);
    }
}

static int count_1(char const *str)
{
    int y = 0;
    int x = 0;
    int i = 0;
    int nb = my_strlen(str);

    while (i < nb) {
        if (c_to_skip(str[i]) == 0) {
            for (x = 0; str[i + x] != '\0' && c_to_skip(str[i + x]) == 0; x++);
            y++;
            i += x;
        } else {
            i++;
        }
    }
    return (y + 1);
}

static int count_2(char const *str, int n)
{
    int y = 0;
    int x = 0;
    int i = 0;
    int nb = my_strlen(str);

    while (i < nb && y <= n) {
        if (c_to_skip(str[i]) == 0) {
            for (x = 0; str[i + x] != '\0' && c_to_skip(str[i + x]) == 0; x++);
            y++;
            i += x;
        } else {
            i++;
        }
    }
    x++;
    return (x);
}

char **my_str_to_word_array(char const *str)
{
    int y = 0;
    int x = 0;
    int i = 0;
    char **dest = malloc(sizeof(char *) * count_1(str));

    while (i < my_strlen(str)) {
        if (c_to_skip(str[i]) == 0) {
            dest[y] = malloc(sizeof(char) * count_2(str, y));
            for (x = 0; str[i + x] != '\0'
                && c_to_skip(str[i + x]) == 0; x++)
                dest[y][x] = str[i + x];
            dest[y][x] = '\0';
            y++;
            i += x;
        } else {
            i++;
        }
    }
    dest[y] = 0;
    return (dest);
}