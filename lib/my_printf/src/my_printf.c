/*
** EPITECH PROJECT, 2020
** my_printf.c
** File description:
** this is the main file for my_printf
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"

struct test {
        char a;
        void (*tab)(va_list ap, char *tmp);
};

struct test flags[12] = {
    {'c', wrapper_character},
    {'i', wrapper_integrer},
    {'d', wrapper_integrer},
    {'o', wrapper_octal},
    {'s', wrapper_string},
    {'u', wrapper_unsigned_int},
    {'x', wrapper_hexadecimal},
    {'X', wrapper_hexadecimal_up},
    {'p', wrapper_pointer},
    {'b', wrapper_binary},
    {'S', wrapper_show_str},
    {'%', wrapper_porcentage},
};

int run_functions(va_list ap, char *str)
{
    char str_dup[50] = {0};

    my_strcpy(str_dup, str);
    for (int x = 0; x < 12; x++) {
        if (str[my_strlen(str) - 1] == flags[x].a) {
            flags[x].tab(ap, str_dup);
            return (1);
        }
    }
    return (0);
}

char *get_string(char *dest , const char *str, int i)
{
    int x = 0;
    int end = 0;

    for (x = 0; str[i + x] != '\0' && end == 0; x++) {
        dest[x] = str[i + x];
        for (int y = 0; y < 12; y++) {
            if (str[i + x] == flags[y].a)
                end++;
        }
    }
    dest[x] = '\0';
    return (dest);
}

int my_printf(const char *str, ...)
{
    char tmp[13];

    va_list(ap);
    va_start(ap, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%') {
            get_string(tmp, str, i + 1);
            if (run_functions(ap, tmp) == 0) {
                my_putchar('%');
                my_putstr(tmp);
            }
        i += my_strlen(tmp);
        } else
            my_putchar(str[i]);
    }
    va_end(ap);
    return (0);
}