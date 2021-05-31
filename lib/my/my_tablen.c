/*
** EPITECH PROJECT, 2021
** my_tablen.c
** File description:
** this is the file to get len of a tab
*/

#include <stdarg.h>

int my_tablen(char **tab)
{
    int len = 0;

    for (; tab[len]; len++);
    return (len);
}