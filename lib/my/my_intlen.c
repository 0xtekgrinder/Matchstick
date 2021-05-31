/*
** EPITECH PROJECT, 2021
** my_intlen.c
** File description:
** this is the file to compute int len
*/

int my_intlen(int nb)
{
    int count = 0;

    for (; nb != 0; count++)
        nb /= 10;
    return (count);
}