/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** task03
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int nb2 = my_strlen(dest);

    for (int i = 0; i < nb; i++)
        dest[nb2 + i] = src[i];
    dest[nb2 + nb] = '\0';
    return (dest);
}