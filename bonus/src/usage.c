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
    my_putstr(" [-i1 FIRST_IA] [-i2 SECOND_IA] [-p PLAYER]\n\n");
    my_putstr("OPTIONS\n -g\t1: player vs player\n");
    my_putstr("\t2: player vs IA\n");
    my_putstr("\t3: IA vs player\n");
    my_putstr("\t4: IA vs IA\n\n");
    my_putstr("-i1/i2\t1: strong IA\n");
    my_putstr("\t2: medium IA\n");
    my_putstr("\t3: low IA\n");
    my_putstr("\t4: very low IA\n\n");
}
