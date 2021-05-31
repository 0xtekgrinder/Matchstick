/*
** EPITECH PROJECT, 2020
** octal.c
** File description:
** file for computing octal numbers
*/

#include "my_printf.h"

void octal(int nb)
{
    int carry = 0;
    int i = 0;
    char tmp[20];

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    for (i = 0; nb != 0; i++) {
        carry = nb % 8;
        tmp[i] = carry + '0';
        nb /= 8;
    }
    tmp[i] = '\0';
    my_revstr(tmp);
    my_putstr(tmp);
}