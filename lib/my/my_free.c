/*
** EPITECH PROJECT, 2021
** my_free.c
** File description:
** this is the file to free
*/

#include <stdlib.h>
#include <stdarg.h>

static void free_2d(void **ptr)
{
    for (int i = 0; ptr[i]; i++)
        free(ptr[i]);
    free(ptr);
}

static void free_3d(void ***ptr)
{
    for (int i = 0; ptr[i]; i++)
        for (int x = 0; ptr[i][x]; x++)
            free(ptr[i][x]);
    free(ptr);
}

void my_free(char *list, ...)
{
    va_list ap;
    void *a;
    void **b;
    void ***c;

    va_start(ap, list);
    for (int p = 0; list[p]; p++) {
        if (list[p] == '1') {
            a = va_arg(ap, void *);
            free(a);
        }
        if (list[p] == '2') {
            b = va_arg(ap, void **);
            free_2d(b);
        } else if (list[p] == '3') {
            c = va_arg(ap, void ***);
            free_3d(c);
        }
    }
    va_end(ap);
}