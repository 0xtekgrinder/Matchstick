/*
** EPITECH PROJECT, 2021
** matchsticks
** File description:
** main
*/

#ifndef MAIN_H_
#define MAIN_H_

static const int EXIT_ERROR = 84;

typedef struct game_tools_s {
    int max_sticks;
    char **map;
} game_tools_t;

int player_ia(game_tools_t game_tools, int ia);
int ia_player(game_tools_t game_tools, int ia);
int ia_ia(game_tools_t game_tools, int ia1, int ia2);
int player_player(game_tools_t game_tools, int player);
void usage(void);
int error_handling(int argc, char **argv);
void create_game_tools(game_tools_t *game_tools, char **argv);
int game_loop(game_tools_t game_tools);

#endif /* !MAIN_H_ */