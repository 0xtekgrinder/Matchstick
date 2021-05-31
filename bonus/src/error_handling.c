/*
** EPITECH PROJECT, 2021
** error_handling.c
** File description:
** this is the file for the error handling
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my.h"

static bool is_nb_lines_ok(char *nb_lines)
{
    int nb = 0;

    if (my_str_isnum(nb_lines) == 0) {
        my_put_error("Error: the number lines needs to be a number\n");
        return (false);
    }
    nb = my_getnbr(nb_lines);
    if (1 >= nb || nb >= 100) {
        my_put_error("Error: number of lines isn't between 1 and 99\n");
        return (false);
    }
    return (true);
}

static bool is_max_sticks_ok(char *max_sticks)
{
    int nb = 0;

    if (my_str_isnum(max_sticks) == 0) {
        my_put_error("Error: max sticks needs to be a number\n");
        return (false);
    }
    nb = my_getnbr(max_sticks);
    if (nb <= 0) {
        my_put_error("Error: max sticks needs to be positive\n");
        return (false);
    }
    return (true);
}

static bool is_ia_ok(char *option, char *ia)
{
    int nb = 0;

    if (my_strcmp("-i1", option) != 0 && my_strcmp("-i2", option) != 0 ) {
        my_put_error("Error: The IA options needs to be ""-i1"" or ""-i2""\n");
        return (false);
    }
    if (my_str_isnum(ia) == 0) {
        my_put_error("Error: The first and second IA needs to be a number\n");
        return (false);
    }
    nb = my_getnbr(ia);
    if (nb < 1 || nb > 4) {
        my_put_error("Error: the first and second IA needs to be between 1");
        my_put_error(" and 4\n");
        return (false);
    }
    return (true);
}

static bool is_gamemode_ok(char *option, char *gamemode)
{
    int nb = 0;

    if (my_strcmp("-g", option) != 0) {
        my_put_error("Error: Forth argument needs to be ""-g""\n");
        return (false);
    }
    if (my_str_isnum(gamemode) == 0) {
        my_put_error("Error: gamemode needs to be a number\n");
        return (false);
    }
    nb = my_getnbr(gamemode);
    if (nb < 1 || nb > 4) {
        my_put_error("Error: gamemode needs to be between 1 and 4\n");
        return (false);
    }
    return (true);
}

int error_handling(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return (EXIT_SUCCESS);
    if (argc < 5 || argc == 6 || argc == 8 || argc > 9) {
        my_put_error("Error: wrong number of arguments\n");
        return (EXIT_FAILURE);
    }
    if (!is_nb_lines_ok(argv[1]) || !is_max_sticks_ok(argv[2])
        || !is_gamemode_ok(argv[3], argv[4]))
        return (EXIT_FAILURE);
    if (argc >= 7 && my_strcmp(argv[5], "-p") == 0
        && my_str_isnum(argv[6]) && (my_getnbr(argv[6]) == 1
        || my_getnbr(argv[6]) == 2))
        return (EXIT_SUCCESS);
    if (argc >= 7 && !is_ia_ok(argv[5], argv[6]))
        return (EXIT_FAILURE);
    if (argc == 9 && !is_ia_ok(argv[7], argv[8]))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}