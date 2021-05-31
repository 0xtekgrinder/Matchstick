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
    int map_len = my_tablen(game_tools.map);

    while (1) {
        *line = rand() % (map_len - 2) + 1;
        if (get_sticks(game_tools.map[*line]) == 0)
            continue;
        *amount_to_remove = rand() % get_sticks(game_tools.map[*line]) + 1;
        if (*amount_to_remove > game_tools.max_sticks)
            continue;
        break;
    }
}

void artificial_inteligence_low(game_tools_t game_tools, int *line
    , int *amount_to_remove)
{
        default_play(game_tools, line, amount_to_remove);
}