/*
** EPITECH PROJECT, 2021
** check_win.c
** File description:
** this is the file to check the win
*/

#include <stdbool.h>
#include "check_win.h"

bool is_it_a_win(char **map)
{
    for (int i = 0; map[i]; ++i)
        if (get_sticks(map[i]) != 0)
            return (false);
    return (true);
}