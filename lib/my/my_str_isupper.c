/*
** EPITECH PROJECT, 2020
** my_str_is_upper
** File description:
** task15
*/

int my_strlen(char const *str);

int my_str_isupper(char const *str)
{
    int nb = my_strlen(str);
    int i = 0;

    for (; i <= nb && str[i] >= 'A' && str[i] <= 'Z'; i++);
    if (i == nb || nb == 0)
        return (1);
    else
        return (0);
}