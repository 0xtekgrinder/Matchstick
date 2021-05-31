/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** this is the main file of matchstick
*/

#include <stdlib.h>
#include "main.h"
#include "my.h"

static void play_gamemodes(int *return_value, char **argv
    , game_tools_t game_tools)
{
    switch (my_getnbr(argv[4])) {
        case 1:
            *return_value = player_player(game_tools, my_getnbr(argv[6]));
            break;
        case 2:
            *return_value = player_ia(game_tools, my_getnbr(argv[6]));
            break;
        case 3:
            *return_value = ia_player(game_tools, my_getnbr(argv[6]));
            break;
        case 4:
            *return_value = ia_ia(game_tools, my_getnbr(argv[6])
                , my_getnbr(argv[8]));
            break;
    }
}

int main(int argc, char **argv)
{
    int return_value = 0;
    game_tools_t game_tools;

    if (error_handling(argc, argv) == EXIT_FAILURE)
        return (EXIT_ERROR);
    if (my_strcmp(argv[1], "-h") == 0) {
        usage();
        return (EXIT_SUCCESS);
    }
    create_game_tools(&game_tools, argv);
    if (game_tools.map == NULL)
        return (EXIT_ERROR);
    play_gamemodes(&return_value, argv, game_tools);
    my_free("2", game_tools.map);
    return (return_value);
}