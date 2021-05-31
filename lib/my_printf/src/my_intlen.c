/*
** EPITECH PROJECT, 2020
** my_intlen.c
** File description:
** this is the file to know the lengh of an intergrer
*/

int my_intlen(long long int nb)
{
    int count = 0;

    if (nb < 0) {
        nb *= -1;
        count++;
    }
    for (; nb != 0; count++)
        nb /= 10;
    return (count);
}