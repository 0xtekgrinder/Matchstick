/*
** EPITECH PROJECT, 2021
** check_input.c
** File description:
** this is the file to check the input
*/

#include <stdbool.h>
#include "check_input.h"
#include "my.h"

bool is_line_ok(char *line, int rows)
{
    int nb_line;

    if (my_str_isnum(line) == 0 || my_strlen(line) == 0) {
        my_printf("Error: invalid input (positive number expected)\n");
        return (false);
    }
    nb_line = my_getnbr(line);
    if (nb_line > rows - 2 || nb_line <= 0) {
        my_printf("Error: this line is out of range\n");
        return (false);
    }
    return (true);
}

static bool is_nb_matches_ok(char *map_line, int nb_matches)
{
    int sticks_count = get_sticks(map_line);

    if (sticks_count < nb_matches)
        return (false);
    return (true);
}

bool is_matches_ok(char *matches, char *map_line, int max_sticks)
{
    int nb_matches;

    if (my_str_isnum(matches) == 0 || my_strlen(matches) == 0) {
        my_printf("Error: invalid input (positive number expected)\n");
        return (false);
    }
    nb_matches = my_getnbr(matches);
    if (nb_matches > max_sticks) {
        my_printf("Error: you cannot remove more than %d matches per turn\n"
            , max_sticks);
        return (false);
    }
    if (nb_matches <= 0) {
        my_printf("Error: you have to remove at least one match\n");
        return (false);
    }
    if (is_nb_matches_ok(map_line, nb_matches) == false) {
        my_printf("Error: not enough matches on this line\n");
        return (false);
    }
    return (true);
}