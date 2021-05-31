/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** task02
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int nb2 = my_strlen(dest);

    for (int i = 0; i < n; i++)
        dest[i] = src[i];
    if (n > nb2)
        dest[nb2 - 1] = '\0';
    return (dest);
}
