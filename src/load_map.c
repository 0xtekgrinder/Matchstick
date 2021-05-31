/*
** EPITECH PROJECT, 2021
** load_map.c
** File description:
** this is the file to load the map
*/

#include "load_map.h"
#include "my.h"

char **load_map(int nb_lines)
{
    char **map = tab_malloc(ROWS(nb_lines), COLS(nb_lines));

    if (map == NULL)
        return (NULL);
    my_memset(map[0], '*', COLS(nb_lines));
    my_memset(map[ROWS(nb_lines) - 1], '*', COLS(nb_lines));
    for (int i = 1; i < ROWS(nb_lines) - 1; i++) {
        my_memset(map[i], ' ', COLS(nb_lines));
        map[i][0] = '*';
        map[i][COLS(nb_lines) - 1] = '*';
        for (int x = COLS(nb_lines) / 2 - (i - 1);
            x < COLS(nb_lines) / 2 + (i - 1) + 1;
            x++)
            map[i][x] = '|';
    }
    return (map);
}