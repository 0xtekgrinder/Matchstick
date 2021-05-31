/*
** EPITECH PROJECT, 2020
** str_change.c
** File description:
** this is the file to remoove the n first character of a string
*/

void str_change(char *str, int nb)
{
    int i = 0;

    for (; str[i + nb] != '\0'; i++)
        str[i] = str[i + nb];
    str[i] = '\0';
}