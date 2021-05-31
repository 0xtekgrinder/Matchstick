/*
** EPITECH PROJECT, 2020
** my_str_create.c
** File description:
** this is the file to create a string starting from a point to another
*/

#include <stdlib.h>

char *my_str_create(char *str, int start_offset, int end_offset)
{
    int i = 0;
    char *result = malloc(sizeof(char) * (end_offset - start_offset + 2));

    for (; i <= end_offset - start_offset; i++)
        result[i] = str[i + start_offset];
    result[i] = '\0';
    return (result);
}