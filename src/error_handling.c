/*
** EPITECH PROJECT, 2021
** error_handling.c
** File description:
** this is the file for the error handling
*/

#include <stdlib.h>
#include "my.h"

int error_handling(int argc, char **argv)
{
    int n;

    if (argc != 3) {
        my_put_error("Error: wrong number of arguments\n");
        return (EXIT_FAILURE);
    }
    if (my_str_isnum(argv[1]) == 0 || my_str_isnum(argv[2]) == 0) {
        my_put_error("Error: at least one of the args isn't a number\n");
        return (EXIT_FAILURE);
    }
    n = my_getnbr(argv[1]);
    if (1 >= n || n >= 100) {
        my_put_error("Error: number of matchstick isn't between 0 and 100\n");
        return (EXIT_FAILURE);
    }
    if (my_getnbr(argv[2]) <= 0) {
        my_put_error("Error: max matchstick needs to be positive\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}