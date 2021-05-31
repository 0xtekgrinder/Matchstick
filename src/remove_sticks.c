/*
** EPITECH PROJECT, 2021
** remove_sticks.c
** File description:
** this is the file to remove the matchsticks
*/

#include <stddef.h>
#include "my.h"

void remove_sticks(char **map, int line, int matches)
{
    size_t sticks_count = 0;

    for (int i = my_strlen(map[line]) - 1; map[line][i]; --i) {
        if (sticks_count == (size_t) matches)
            return;
        if (map[line][i] == '|') {
            map[line][i] = ' ';
            sticks_count++;
        }
    }
}