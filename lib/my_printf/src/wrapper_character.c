/*
** EPITECH PROJECT, 2020
** wrapper_character.c
** File description:
** this is the file for character specifier
*/

#include <stdarg.h>
#include "my_printf.h"

static void width(char *str)
{
    int nb = my_getnbr(str);

    for (int i = 0; i < nb - 1; i++)
        my_putchar(' ');
}

void wrapper_character(va_list ap, char *str)
{
    char a = va_arg(ap, int);

    if (str[0] != '-')
        width(str);
    my_putchar(a);
    if (str[0] == '-') {
        str_change(str, 1);
        width(str);
    }
}