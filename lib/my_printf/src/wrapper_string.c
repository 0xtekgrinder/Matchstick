/*
** EPITECH PROJECT, 2020
** wrapper_string_1.c
** File description:
** this is the file for string specifier
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"

static int char_is_num(char a)
{
    if (a <= '9' && a >= '0')
        return (1);
    else
        return (0);
}

static void width(char *str, int length)
{
    int n = my_getnbr(str);
    int x = 0;

    for (; str[x] != '\0' && char_is_num(str[x]) == 1; x++);
    if (x == 0)
        return;
    for (int i = 0; i < n - length; i++) {
        my_putchar(' ');
    }
}

static void precision(char *str, char *str1)
{
    int n = 0;
    int i = 0;
    char *tmp = my_strdup(str);
    int length = my_strlen(str1);

    for (; str[i] != '\0'; i++) {
        if (str[i] == '.')
            break;
    }
    if (i != my_strlen(str)) {
        str_change(tmp, i);
        n = my_getnbr(tmp);
        for (int x = 0; x < length - (length - n) && str1[x] != '\0'; x++)
            my_putchar(str1[x]);
    } else
        my_putstr(str1);
    free(tmp);
}

static int precision_length(char *str, char *str1)
{
    int n = my_strlen(str1);
    char *tmp = my_strdup(str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            str_change(tmp, i);
            n = my_getnbr(tmp);
        }
    }
    free(tmp);
    if (n < my_strlen(str1))
        return (n);
    else
        return (my_strlen(str1));
}

void wrapper_string(va_list ap, char *str)
{
    char *tmp = va_arg(ap, char *);
    int n = precision_length(str, tmp);

    if (str[0] != '-') {
        width(str, n);
        precision(str, tmp);
    }
    if (str[0] == '-') {
        str_change(str, 1);
        precision(str, tmp);
        width(str, n);
    }
}