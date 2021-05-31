/*
** EPITECH PROJECT, 2020
** wrapper_binary.c
** File description:
** this is the file for binary specifier
*/

#include <stdarg.h>
#include "my_printf.h"

void wrapper_binary(va_list ap, char *str)
{
    unsigned int nb = va_arg(ap, unsigned int);
    int carry = 0;
    char a[33];
    int i = 0;

    for (i = 0; nb != 0; i++) {
        carry = nb % 2;
        nb /= 2;
        a[i] = carry + '0';
    }
    a[i] = '\0';
    my_revstr(a);
    my_putstr(a);
}