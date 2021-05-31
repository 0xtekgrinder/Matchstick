/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** game_loop.h
*/

#ifndef GAME_LOOP_H_
#define GAME_LOOP_H_

typedef struct game_tools_s {
    int max_sticks;
    char **map;
} game_tools_t;

static const int USER_WIN = 1;
static const int AI_WIN = 2;
static const int END_EOF = 0;
static const int CONTINUE = 10;

void artificial_inteligence(game_tools_t game_tools, int *line
    , int *amount_to_remove);
void remove_sticks(char **map, int line, int matches);
int game_loop(game_tools_t game_tools);
int get_input(FILE *stream, char *buff_dup);
bool is_line_ok(char *line, int rows);
bool is_matches_ok(char *matches, char *map_line, int max_sticks);
bool is_it_a_win(char **map);

#endif /* !GAME_LOOP_H_ */
