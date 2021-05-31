/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** task05
*/

int my_compute_power_rec(int nb, int power);

int my_compute_square_root(int nb)
{
    int end = 0;
    int result = 0;

    for (int i = nb; i > 0 && end == 0; i--) {
        if (my_compute_power_rec(i, 2) == nb) {
            end++;
            result = i;
        }
    }
    return (result);
}
