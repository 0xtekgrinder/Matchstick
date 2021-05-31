/*
** EPITECH PROJECT, 2020
** my_put_str
** File description:
** This
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
    return (0);
}
