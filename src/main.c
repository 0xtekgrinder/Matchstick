/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** this is the main file of matchstick
*/

#include <stdlib.h>
#include "main.h"
#include "my.h"

int main(int argc, char **argv)
{
    int return_value = 0;
    game_tools_t game_tools;

    if (error_handling(argc, argv) == EXIT_FAILURE)
        return (EXIT_ERROR);
    create_game_tools(&game_tools, argv);
    if (game_tools.map == NULL)
        return (EXIT_ERROR);
    return_value = game_loop(game_tools);
    my_free("2", game_tools.map);
    return (return_value);
}
