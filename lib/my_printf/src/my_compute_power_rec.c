/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** task04
*/

int my_compute_power_rec(int nb, int power)
{
    int result = nb;

    if (power > 0) {
        result = nb * my_compute_power_rec(nb, power - 1);
    } else {
        if (power == 0) {
            result = 1;
        } else {
            result = 0;
        }
    }
    return (result);
}
