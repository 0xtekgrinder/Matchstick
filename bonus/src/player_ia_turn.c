/*
** EPITECH PROJECT, 2021
** game_loop.c
** File description:
** this is the file for the game_loop
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "player_ia_turn.h"
#include "my.h"

int player_turn(game_tools_t game_tools, FILE *stream)
{
    char line[512];
    char matches[512];

    my_printf("\nYour turn:\n");
    while (1) {
        my_printf("Line: ");
        if (get_input(stream, line) == EXIT_FAILURE)
            return (END_EOF);
        if (!is_line_ok(line, my_tablen(game_tools.map)))
            continue;
        my_printf("Matches: ");
        if (get_input(stream, matches) == EXIT_FAILURE)
            return (END_EOF);
        if (!is_matches_ok(matches, game_tools.map[my_getnbr(line)]
            , game_tools.max_sticks))
            continue;
        break;
    }
    remove_sticks(game_tools.map, my_getnbr(line), my_getnbr(matches));
    my_printf("Player removed %s match(es) from line %s\n", matches, line);
    return (CONTINUE);
}

void ai_turn(game_tools_t game_tools, int ia)
{
    int line = 0;
    int amount_to_remove = 0;

    my_printf("\nAI's turn...\n");
    artificial_inteligence[ia - 1](game_tools, &line, &amount_to_remove);
    remove_sticks(game_tools.map, line, amount_to_remove);
    my_printf("AI removed %d match(es) from line %d\n"
                    , amount_to_remove, line);
}