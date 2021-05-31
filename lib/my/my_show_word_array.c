/*
** EPITECH PROJECT, 2020
** my_show_word_array
** File description:
** task03
*/

int my_putstr(char const *str);

int my_show_word_array(char **tab)
{
    for (int i = 0; tab[i]; i++) {
        my_putstr(tab[i]);
        my_putstr("\n");
    }
    return (0);
}
