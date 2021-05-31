/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** This
*/

int my_strlen(char const *str)
{
    int nb = 0;

    for (; str[nb]; nb++);
    return (nb);
}