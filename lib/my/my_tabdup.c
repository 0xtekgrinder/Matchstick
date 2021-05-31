/*
** EPITECH PROJECT, 2021
** dup_tab.c
** File description:
** this is the file to dub a tab
*/

#include <stdlib.h>

char *my_strdup(char const *src);

char **my_tabdup(char **tab)
{
    size_t len = 0;
    char **tab_dup;

    for (; tab[len]; len++);
    tab_dup = malloc(sizeof(char *) * (len + 1));
    tab_dup[len] = NULL;
    for (int i = 0; tab[i]; i++)
        tab_dup[i] = my_strdup(tab[i]);
    return (tab_dup);
}