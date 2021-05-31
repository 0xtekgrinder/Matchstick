/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** This
*/

int my_strlen(char const *str)
{
    int nb = 0;

    for (int end = 1; end == 1; nb++) {
        if (str[nb] == '\0') {
            end++;
        }
    }
    nb--;
    return (nb);
}
