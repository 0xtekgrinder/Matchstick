/*
** EPITECH PROJECT, 2020
** my_str_islower
** File description:
** task14
*/

int my_strlen(char const *str);

int my_str_islower(char const *str)
{
    int nb = my_strlen(str);
    int i = 0;

    for (; i <= nb && str[i] >= 'a' && str[i] <= 'z'; i++);
    if (i == nb || nb == 0)
        return (1);
    else
        return (0);
}