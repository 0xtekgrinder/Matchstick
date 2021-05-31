/*
** EPITECH PROJECT, 2021
** matchstick.h
** File description:
** this is the header file for matchstick
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include <stdio.h>
#include <stdbool.h>

typedef struct game_tools_s {
    int max_sticks;
    char **map;
} game_tools_t;

static const int EXIT_ERROR = 84;
static const int USER_WIN = 1;
static const int AI_WIN = 2;
static const int END_EOF = 0;
static const int CONTINUE = 10;

#define ROWS(x)  ((x) + 2)
#define COLS(x)  (1 + (x - 1) * 2 + 2)

void create_game_tools(game_tools_t *game_tools, char **argv);
int get_input(FILE *stream, char *buff_dup);
int get_sticks(char *map_line);
void artificial_inteligence(game_tools_t game_tools, int *nb_line
    , int *nb_matches);
void remove_sticks(char **map, int line, int matches);
int game_loop(game_tools_t game_tools);
bool is_line_ok(char *line, int rows);
bool is_matches_ok(char *matches, char *map_line, int max_sticks);
bool is_it_a_win(char **map);
int error_handling(int argc, char **argv);
char **load_map(int nb_lines);

#endif /* !MATCHSTICK_H_ */
