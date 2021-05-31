/*
** EPITECH PROJECT, 2020
** my_str_isprintable
** File description:
** task16
*/

int my_strlen(char const *str);

int my_str_isprintable(char const *str)
{
    int nb = my_strlen(str);
    int i = 0;

    for (; i <= nb && (str[i] <= 31 && str[i] >= 0) || str[i] == 127; i++);
    if (i == nb || nb == 0)
        return (1);
    else
        return (0);
}