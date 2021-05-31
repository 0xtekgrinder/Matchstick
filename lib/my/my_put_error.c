/*
** EPITECH PROJECT, 2021
** my_put_error.c
** File description:
** this is the file to put errors
*/

#include "unistd.h"

int my_strlen(char const *str);

void my_put_error(char const *str)
{
    int nb = my_strlen(str);

    write(2, str, nb);
}