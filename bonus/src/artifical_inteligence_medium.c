/*
** EPITECH PROJECT, 2021
** matchsticks
** File description:
** artifical_inteligence_medium.c
*/

#include <stdlib.h>
#include "artifical_inteligence.h"
#include "my.h"

static void end_case(game_tools_t game_tools, int *line, int *amount_to_remove
    , int index)
{
    int count_1 = 0;
    int nb_matches = 0;

    for (int i = 1; game_tools.map[i + 1]; ++i)
        if (get_sticks(game_tools.map[i]) == 1)
            count_1 += 1;
    *line = index;
    nb_matches = get_sticks(game_tools.map[*line]);
    if (nb_matches > game_tools.max_sticks) {
        *amount_to_remove = game_tools.max_sticks
            - nb_matches / game_tools.max_sticks;
        return;
    }
    *amount_to_remove = count_1 % 2 != 0 ? nb_matches : nb_matches - 1;
}

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

void artificial_inteligence_medium(game_tools_t game_tools, int *line
    , int *amount_to_remove)
{
    int count_2_or_more = 0;
    int nb_matchsticks = 0;
    int index = 0;

    for (int i = 1; game_tools.map[i + 1]; ++i) {
        nb_matchsticks = get_sticks(game_tools.map[i]);
        if (nb_matchsticks >= 2) {
            count_2_or_more++;
            index = i;
        }
    }
    if (count_2_or_more == 1)
        end_case(game_tools, line, amount_to_remove, index);
    else
        default_play(game_tools, line, amount_to_remove);
}