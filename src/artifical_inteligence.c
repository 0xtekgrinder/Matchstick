/*
** EPITECH PROJECT, 2021
** algorithm.c
** File description:
** this is the file for the IA
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "artifical_inteligence.h"

static int compute_nim_sum(char **map, int nb, int index)
{
    if (!map[index])
        return (nb);
    return (compute_nim_sum(map, nb ^ get_sticks(map[index]), index + 1));
}

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
    if (count_1 % 2 != 0)
        *amount_to_remove = nb_matches;
    else
        *amount_to_remove = nb_matches - 1;
}

static void default_play(game_tools_t game_tools, int *line
    , int *amount_to_remove)
{
    int nb_sticks = 0;
    int nim_sum = compute_nim_sum(game_tools.map
        , get_sticks(game_tools.map[0]), 1);

    for (int i = 1; game_tools.map[i + 1]; ++i) {
        nb_sticks = get_sticks(game_tools.map[i]);
        if ((nim_sum ^ nb_sticks) < nb_sticks) {
            *amount_to_remove = nb_sticks - (nim_sum ^ nb_sticks);
            if (*amount_to_remove > game_tools.max_sticks)
                *amount_to_remove = game_tools.max_sticks;
            *line = i;
            break;
        }
    }
}

static void on_error(game_tools_t game_tools, int *line, int *amount_to_remove)
{
    for (int i = 1; game_tools.map[i + 1]; ++i)
        if (get_sticks(game_tools.map[i]) != 0) {
            *line = i;
            *amount_to_remove = 1;
            break;
        }
}

void artificial_inteligence(game_tools_t game_tools, int *line
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
    if (*line == 0)
        on_error(game_tools, line, amount_to_remove);
}