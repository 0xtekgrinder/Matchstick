/*
** EPITECH PROJECT, 2020
** my_showstr
** File description:
** this
*/

int my_strlen(char const *str);

void my_putchar(char c);

int my_put_nbr(int nb);

static int my_char_isprintable(char a)
{
    if (a <= 31 && a >= 0)
        return (1);
    else
        return (0);
}

static void disp_dec_to_hexa(int nb)
{
    if (nb < 16)
        my_put_nbr(0);
    while (nb != 0) {
        if (nb % 16 < 10)
            my_put_nbr(nb % 16);
        else
            my_putchar('a' + (nb % 16) - 10);
        nb /= 16;
    }
}

int my_showstr(char const *str)
{
    int nb = my_strlen(str);

    for (int i = 0; i < nb; i++) {
        if (my_char_isprintable(str[i]) == 0)
            my_putchar(str[i]);
        else {
            my_putchar('\\');
            disp_dec_to_hexa(str[i]);
        }
    }
    return (0);
}
