/*
** EPITECH PROJECT, 2021
** matchsticks
** File description:
** usage.c
*/

#include "my.h"

void usage(void)
{
    my_putstr("");
    my_putstr("\nMatchstick game created by Matéo VIEL for a Epitech project");
    my_putstr("\n\nUSAGE:\n ./matchstick_bonus nb_lines max_sticks -g GAMEMODE");
    my_putstr(" [-i1 FIRST_AI] [-i2 SECOND_AI] [-p PLAYER]\n\n");
    my_putstr("OPTIONS\n -g\t1: player vs player\n");
    my_putstr("\t2: player vs AI\n");
    my_putstr("\t3: AI vs player\n");
    my_putstr("\t4: AI vs AI\n\n");
    my_putstr("-i1/i2\t1: strong AI\n");
    my_putstr("\t2: medium AI\n");
    my_putstr("\t3: low AI\n");
    my_putstr("\t4: very low AI\n\n");
}
