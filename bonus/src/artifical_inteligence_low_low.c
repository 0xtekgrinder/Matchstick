/*
** EPITECH PROJECT, 2021
** matchsticks
** File description:
** artifical_inteligence_medium.c
*/

#include <stdlib.h>
#include "artifical_inteligence.h"
#include "my.h"

static void default_play(game_tools_t game_tools, int *line
    , int *amount_to_remove)
{
    for (int i = 1; game_tools.map[i + 1]; ++i)
        if (get_sticks(game_tools.map[i]) != 0) {
            *line = i;
            *amount_to_remove = 1;
            break;
        }
}

void artificial_inteligence_low_low(game_tools_t game_tools, int *line
    , int *amount_to_remove)
{
        default_play(game_tools, line, amount_to_remove);
}