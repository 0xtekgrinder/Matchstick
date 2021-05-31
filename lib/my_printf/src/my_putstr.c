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
    int end = 1;

    for (end = 1; end == 1; nb++) {
        if (str[nb] == '\0') {
            end++;
        } else {
        my_putchar(str[nb]);
        }
    }
    return (0);
}
