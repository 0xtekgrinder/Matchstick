/*
** EPITECH PROJECT, 2020
** tab_malloc.c
** File description:
** this is the file to malloc a tab
*/

#include <stdlib.h>

char **tab_malloc(int rows, int cols)
{
    char **tab = malloc(sizeof(char *) * (rows + 1));
    int i = 0;

    if (tab == NULL)
        return (NULL);
    for (; i < rows; i++) {
        tab[i] = malloc(sizeof(char) * (cols + 1));
        if (tab[i] == NULL) {
            free(tab);
            return (NULL);
        }
        tab[i][cols] = '\0';
    }
    tab[i] = NULL;
    return (tab);
}