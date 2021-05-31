/*
** EPITECH PROJECT, 2021
** get_input.c
** File description:
** this is the file to get the input
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int get_input(FILE *stream, char *buff_dup)
{
    size_t len = 0;
    char *buff = NULL;

    if (getline(&buff, &len, stream) == -1) {
        free(buff);
        return (EXIT_FAILURE);
    }
    buff[my_strlen(buff) - 1] = '\0';
    my_strcpy(buff_dup, buff);
    free(buff);
    return (EXIT_SUCCESS);
}