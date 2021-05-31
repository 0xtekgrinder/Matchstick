/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** task13
*/

int my_strlen(char const *str);

int my_str_isnum(char const *str)
{
    int nb = my_strlen(str);
    int i = 0;

    for (; i <= nb && str[i] >= '0' && str[i] <= '9'; i++);
    if (i == nb || nb == 0)
        return (1);
    else
        return (0);
}