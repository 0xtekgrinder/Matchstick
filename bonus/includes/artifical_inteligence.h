/*
** EPITECH PROJECT, 2021
** matchsticks
** File description:
** artificial_inteligence
*/

#ifndef ARTIFICIAL_INTELIGENCE_H_
#define ARTIFICIAL_INTELIGENCE_H_

typedef struct game_tools_s {
    int max_sticks;
    char **map;
} game_tools_t;

int get_sticks(char *map_line);

#endif /* !ARTIFICIAL_INTELIGENCE_H_ */