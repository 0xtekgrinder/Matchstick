/*
** EPITECH PROJECT, 2021
** matchticks
** File description:
** create_game_tools.h
*/

#ifndef CREATE_GAME_TOOLS_H_
#define CREATE_GAME_TOOLS_H_

typedef struct game_tools_s {
    int max_sticks;
    char **map;
} game_tools_t;

char **load_map(int nb_lines);

#endif /* !CREATE_GAME_TOOLS_H_ */
