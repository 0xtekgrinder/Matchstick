/*
** EPITECH PROJECT, 2020
** my_find_prime_sup
** File description:
** this
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int i = nb;

    for (i = nb; my_is_prime(i) != 1; i++);
    return (i);
}
