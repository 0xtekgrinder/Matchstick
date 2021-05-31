/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** this
*/

#include <stdlib.h>

void my_putchar(char c);

int my_put_nbr(long long int nb)
{
    if (nb < 0) {
        nb *= -1;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar('0' + (nb % 10));
    }
    if (nb < 10 && nb >= 0) {
        my_putchar('0' + (nb % 10));
    }
    return (0);
}