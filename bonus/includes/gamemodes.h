/*
** EPITECH PROJECT, 2021
** matcsticks
** File description:
** gamemodes
*/

#ifndef GAMEMODES_H_
#define GAMEMODES_H_

static const int USER_WIN = 1;
static const int AI_WIN = 2;
static const int END_EOF = 0;

typedef struct game_tools_s {
    int max_sticks;
    char **map;
} game_tools_t;

int player_turn(game_tools_t game_tools, FILE *stream);
void ai_turn(game_tools_t game_tools, int ia);
bool is_it_a_win(char **map);

#endif /* !GAMEMODES_H_ */