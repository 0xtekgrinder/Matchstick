/*
** EPITECH PROJECT, 2020
** wrapper_hexadecimal_2.c
** File description:
** this is the file for heXadecimal specifier
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"

static void flags(char *str, int nb)
{
    int flag = 0;
    int precision = 0;
    int width = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '#') {
            flag++;
        }
        if (str[i] == '.')
            precision++;
    }
    if (str[1] == '0')
        width++;
    if (nb == 1 && flag == 1 && width == 1)
        my_putstr("0X");
    if (nb == 2 && flag == 1 && width == 0)
        my_putstr("0X");
    if (nb == 3 && flag == 1 && (width == 0 || width == 1))
        my_putstr("0X");
}

static void width(char *str, int nb, int length)
{
    int flag = 0;
    int x = 0;
    int precision = 0;

    for (int y = 0; str[y] != '\0'; y++)
        if (str[y] == '#')
            flag = 2;
    for (int x = 0; str[x] != '\0'; x++) {
        if (str[x] == '.')
            precision = 1;
    }
    for (int i = 0; i < my_getnbr(str) - (length + flag); i++) {
        if (((str[0] == '#' && str[1] == '0') || str[0] == '0')
            && precision == 0)
            my_putchar('0');
        else
            my_putchar(' ');
    }
}

static void precision(char *str, int nb)
{
    int length = 0;
    int nb_cpy = nb;
    int n = 0;
    int i = 0;
    char *tmp = my_strdup(str);

    for (; nb_cpy != 0; length++) {
        nb_cpy /= 16;
    }
    for (; str[i] != '\0'; i++) {
        if (str[i] == '.')
            break;
    }
    if (i != my_strlen(str) + 1) {
        str_change(tmp, i);
        n = my_getnbr(tmp);
    }
    for (int x = 0; x < n - length; x++)
        my_putchar('0');
    free(tmp);
}

static int precision_length(char *str, int nb)
{
    int nb_cpy = nb;
    int n = 0;
    char *tmp = my_strdup(str);

    for (; nb_cpy != 0; n++) {
        nb_cpy /= 16;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            str_change(tmp, i);
            if (my_getnbr(tmp) > n)
                n = my_getnbr(tmp);
        }
    }
    free(tmp);
    return (n);
}

void wrapper_hexadecimal_up(va_list ap, char *str)
{
    unsigned int nb = va_arg(ap, unsigned int);
    int length = precision_length(str, nb);

    if (str[0] != '-') {
        flags(str, 1);
        width(str, nb, length);
        flags(str, 2);
        precision(str, nb);
        hexadecimal(nb, 0);
    }
    if (str[0] == '-') {
        str_change(str, 1);
        flags(str, 3);
        precision(str, nb);
        hexadecimal(nb, 0);
        width(str, nb, length);
    }
}