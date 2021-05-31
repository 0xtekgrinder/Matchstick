/*
** EPITECH PROJECT, 2021
** matchsticks
** File description:
** player_ia_turn
*/

#ifndef PLAYER_IA_TURN_H_
#define PLAYER_IA_TURN_H_

static const int END_EOF = 0;
static const int CONTINUE = 10;

typedef struct game_tools_s {
    int max_sticks;
    char **map;
} game_tools_t;

void artificial_inteligence_low_low(game_tools_t game_tools, int *line
    , int *amount_to_remove);
void artificial_inteligence_low(game_tools_t game_tools, int *line
    , int *amount_to_remove);
void artificial_inteligence_medium(game_tools_t game_tools, int *line
    , int *amount_to_remove);
void artificial_inteligence_strong(game_tools_t game_tools, int *line
    , int *amount_to_remove);
int get_input(FILE *stream, char *buff_dup);
bool is_line_ok(char *line, int rows);
bool is_matches_ok(char *matches, char *map_line, int max_sticks);
void remove_sticks(char **map, int line, int matches);

void (*artificial_inteligence[4])(game_tools_t game_tools, int *line
    , int *amount_to_remove) = {
    artificial_inteligence_strong,
    artificial_inteligence_medium,
    artificial_inteligence_low,
    artificial_inteligence_low_low,
};

#endif /* !PLAYER_IA_TURN_H_ */