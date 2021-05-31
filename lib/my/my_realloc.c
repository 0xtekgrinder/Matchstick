/*
** EPITECH PROJECT, 2021
** my_realloc.c
** File description:
** this is the file to my_realloc
*/

#include <string.h>
#include <stddef.h>
#include <stdlib.h>

void my_memset(char *to_fill, char character, int length);

char *my_strcpy(char *dest, char const *src);

void *my_realloc(char *ptr, size_t size)
{
    char *dest = malloc(sizeof(char) * size);

    my_memset(dest, '\0', size - 1);
    if (ptr) {
        my_strcpy(dest, ptr);
        free(ptr);
    }
    return (dest);
}