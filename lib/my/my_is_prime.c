/*
** EPITECH PROJECT, 2020
** my_is_prime
** File description:
** task06
*/

int my_is_prime(int nb)
{
    int result = 0;

    for (int i = nb - 1; i > 1; i--) {
        if (nb % i == 0) {
            result = 1;
            break;
        }
    }
    return (result);
}
