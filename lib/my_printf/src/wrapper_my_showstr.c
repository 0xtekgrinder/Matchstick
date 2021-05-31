/*
** EPITECH PROJECT, 2020
** wrapper_string_2.c
** File description:
** this is the file for character specifier
*/

#include <stdarg.h>
#include "my_printf.h"

void wrapper_show_str(va_list ap, char *str)
{
    char *tmp = va_arg(ap, char *);
    int y = 0;
    int nb = 0;

    for (int i = 0; tmp[i] != '\0'; i++) {
        if (tmp[i] < 32 || tmp[i] == 127) {
            nb = tmp[i];
            for (y = 0; nb != 0; y++)
                nb /= 8;
            my_putchar('\\');
            for (int x = 0; x < 3 - y; x++)
                my_putchar('0');
            octal(tmp[i]);
        } else
            my_putchar(tmp[i]);
    }
}