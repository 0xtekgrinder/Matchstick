/*
** EPITECH PROJECT, 2021
** game_loop.c
** File description:
** this is the file for the game_loop
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "game_loop.h"
#include "my.h"

static int player_turn(game_tools_t game_tools, FILE *stream)
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

static void ai_turn(game_tools_t game_tools)
{
    int line = 0;
    int amount_to_remove = 0;

    my_printf("\nAI's turn...\n");
    artificial_inteligence(game_tools, &line, &amount_to_remove);
    remove_sticks(game_tools.map, line, amount_to_remove);
    my_printf("AI removed %d match(es) from line %d\n"
                    , amount_to_remove, line);
}

int game_loop(game_tools_t game_tools)
{
    while (1) {
        my_show_word_array(game_tools.map);
        if (is_it_a_win(game_tools.map)) {
            my_printf("I lost... snif... but I'll get you next time!!\n");
            return (USER_WIN);
        }
        if (player_turn(game_tools, stdin) == END_EOF)
            return (END_EOF);
        my_show_word_array(game_tools.map);
        if (is_it_a_win(game_tools.map)) {
            my_printf("You lost, too bad...!\n");
            return (AI_WIN);
        }
        ai_turn(game_tools);
    }
}