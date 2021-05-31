/*
** EPITECH PROJECT, 2021
** matchsticks
** File description:
** gamemodes
*/

#include <stdio.h>
#include <stdbool.h>
#include "gamemodes.h"
#include "my.h"

int player_ia(game_tools_t game_tools, int ia)
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
        ai_turn(game_tools, ia);
    }
}

int ia_player(game_tools_t game_tools, int ia)
{
    while (1) {
        my_show_word_array(game_tools.map);
        if (is_it_a_win(game_tools.map)) {
            my_printf("You lost, too bad...!\n");
            return (AI_WIN);
        }
        ai_turn(game_tools, ia);
        my_show_word_array(game_tools.map);
        if (is_it_a_win(game_tools.map)) {
            my_printf("I lost... snif... but I'll get you next time!!\n");
            return (USER_WIN);
        }
        if (player_turn(game_tools, stdin) == END_EOF)
            return (END_EOF);
    }
}

int ia_ia(game_tools_t game_tools, int ia1, int ia2)
{
    while (1) {
        my_show_word_array(game_tools.map);
        if (is_it_a_win(game_tools.map)) {
            my_printf("First IA won!!\n");
            return (AI_WIN);
        }
        ai_turn(game_tools, ia1);
        my_show_word_array(game_tools.map);
        if (is_it_a_win(game_tools.map)) {
            my_printf("Second IA won!!\n");
            return (AI_WIN);
        }
        ai_turn(game_tools, ia2);
    }
}