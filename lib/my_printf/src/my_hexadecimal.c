/*
** EPITECH PROJECT, 2020
** hexadecimal.c
** File description:
** this is the file for hexadecimal
*/

#include "my_printf.h"

void hexadecimal(unsigned int nb, int n)
{
    char a[15];
    int i = 0;
    int carry = 0;

    for (; nb != 0; i++) {
        carry = nb % 16;
        nb /= 16;
        if (carry < 10)
            a[i] = carry + '0';
        else
            a[i] = carry % 10 + 'A' + n;
    }
    a[i] = '\0';
    my_revstr(a);
    my_putstr(a);
}