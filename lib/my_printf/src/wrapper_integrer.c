/*
** EPITECH PROJECT, 2020
** wrapper_integrer.c
** File description:
** this is the file for integrer specifier
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"

static void width(char *str, int nb, int length)
{
    int n = my_getnbr(str);
    int x = 0;
    int precision = 0;

    for (int x = 0; str[x] != '\0'; x++) {
        if (str[x] == '.')
            precision = 1;
        if (str[x] == '+')
            length++;
    }
    for (int i = 0; i < n - length; i++) {
        if (str[0] == '0')
            my_putchar('0');
        if (str[0] != '0' || precision == 1)
            my_putchar(' ');
    }
}

static void precision(char *str, int nb)
{
    int n = 0;
    int i = 0;
    char *tmp = my_strdup(str);

    for (; str[i] != '\0'; i++) {
        if (str[i] == '.')
            break;
    }
    if (i != my_strlen(str) + 1) {
        str_change(tmp, i);
        n = my_getnbr(tmp);
    }
    if (nb < 0) {
        my_putchar('-');
        n++;
    }
    for (int x = 0; x < n - my_intlen(nb); x++)
        my_putchar('0');
    free(tmp);
}

static int precision_length(char *str, int nb)
{
    int n = my_intlen(nb);
    char *tmp = my_strdup(str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            str_change(tmp, i);
            n = my_getnbr(tmp);
        }
    }
    free(tmp);
    return (n);
}

static void flags(char *str, int nb)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '+') {
            if (nb > 0) {
                my_putchar('+');
            }
        }
    }
    if (str[0] == ' '
        && (str[1] == '.' || str[1] == str[my_strlen(str) - 1])) {
        str_change(str, 1);
        my_putchar(' ');
    }
}

void wrapper_integrer(va_list ap, char *str)
{
    int nb = va_arg(ap, int);
    int n = precision_length(str, nb);

    if (str[0] != '-') {
        width(str, nb, n);
        flags(str, nb);
        precision(str, nb);
        my_put_nbr(nb);
    }
    if (str[0] == '-') {
        str_change(str, 1);
        flags(str, nb);
        precision(str, nb);
        my_put_nbr(nb);
        width(str, nb, n);
    }
}