/*
** EPITECH PROJECT, 2021
** create_game_tools.c
** File description:
** this is the file to create game_tools
*/

#include "create_game_tools.h"
#include "my.h"

void create_game_tools(game_tools_t *game_tools, char **argv)
{
    game_tools->map = load_map(my_getnbr(argv[1]));
    game_tools->max_sticks = my_getnbr(argv[2]);
}