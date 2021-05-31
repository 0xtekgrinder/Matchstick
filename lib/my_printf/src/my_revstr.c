/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** task03
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int nb = my_strlen(str);
    char str2[nb];

    for (int i = 0; i < nb; i++) {
        str2[i] = str[nb-i-1];
    }
    for (int x = 0; x < nb; x++) {
        str[x] = str2[x];
    }
    return (str);
}
