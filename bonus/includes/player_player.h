/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-matchstick-mateo.viel
** File description:
** player_player
*/

#ifndef PLAYER_PLAYER_H_
#define PLAYER_PLAYER_H_

static const int USER_WIN = 1;
static const int AI_WIN = 2;
static const int END_EOF = 0;
static const int CONTINUE = 10;

typedef struct game_tools_s {
    int max_sticks;
    char **map;
} game_tools_t;

bool is_it_a_win(char **map);
int get_input(FILE *stream, char *buff_dup);
bool is_line_ok(char *line, int rows);
bool is_matches_ok(char *matches, char *map_line, int max_sticks);
void remove_sticks(char **map, int line, int matches);

#endif /* !PLAYER_PLAYER_H_ */