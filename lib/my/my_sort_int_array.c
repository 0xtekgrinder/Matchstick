/*
** EPITECH PROJECT, 2020
** my_sort_int_array
** File description:
** this
*/

void my_sort_int_array(int *tab, int size)
{
    int nb = 0;

    for (int x = 0; x < size ; x++) {
        for (int i = 0; i < size - 1 - x; i++) {
            if (tab[i] > tab[i + 1]) {
                nb = tab[i + 1];
                tab[i + 1] = tab[i];
                tab[i] = nb;
            }
        }
    }
}
