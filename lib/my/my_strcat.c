/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** task02
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int nb2 = my_strlen(dest);

    for (; src[i]; i++)
        dest[nb2 + i] = src[i];
    dest[nb2 + i] = '\0';
    return (dest);
}
