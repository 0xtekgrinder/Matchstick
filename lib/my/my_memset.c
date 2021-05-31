/*
** EPITECH PROJECT, 2020
** my_memset.c
** File description:
** this is the file for the emmeset function
*/

#include <stdlib.h>

void *my_memset(void *s, int c, size_t n)
{
    char *a = s;

    for (int i = 0; i < n; i++)
        a[i] = c;
    return (s);
}