/*
** EPITECH PROJECT, 2020
** wrapper_pointer.c
** File description:
** this is the file for pointer specifier
*/

#include <stdarg.h>
#include "my_printf.h"

void wrapper_pointer(va_list ap, char *str)
{
    long unsigned int nb = va_arg(ap, long unsigned int);
    char a[25];
    int i = 0;
    int carry = 0;

    for (; nb != 0; i++) {
        carry = nb % 16;
        nb /= 16;
        if (carry < 10)
            a[i] = carry + '0';
        else
            a[i] = carry % 10 + 'a';
    }
    a[i] = '\0';
    my_putstr("0x");
    my_revstr(a);
    my_putstr(a);
}