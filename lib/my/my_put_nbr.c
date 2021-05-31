/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** this
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int	carry;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb >= 10) {
        carry = (nb % 10);
        nb = (nb - carry) / 10;
        my_put_nbr(nb);
        my_putchar('0' + carry);
    } else if (nb >= 0)
        my_putchar('0' + nb % 10);
}
