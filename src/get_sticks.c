/*
** EPITECH PROJECT, 2021
** get_sticks.c
** File description:
** this is the file to get the matchsticks of a line
*/

#include <stddef.h>

int get_sticks(char *map_line)
{
    size_t matchstick_count = 0;

    for (int i = 0; map_line[i]; ++i)
        if (map_line[i] == '|')
            matchstick_count++;
    return (matchstick_count);
}