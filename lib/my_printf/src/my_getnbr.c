/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** this
*/

int my_strlen(char const *str);

int my_compute_power_rec(int nb, int power);

static int char_isnum(char a)
{
    if (a >= '0' && a <= '9')
        return (1);
    else
        return (0);
}

static int count_numbers(char const *str, int x)
{
    int count = 0;
    int end = 0;

    for (int i = 0; i < x && end == 0; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            count++;
        }
        if (char_isnum(str[i]) == 1 &&
            char_isnum(str[i + 1]) == 0)
            end++;
    }
    return (count);
}

static int minuses_or_plus(char const *str, int nb)
{
    int minuses = 0;

    for (int i = 0; i < nb; i++) {
        if (str[i] == '-') {
            minuses++;
        }
        if (str[i] != '-' || str[i] != '+')
            break;
    }
    if (minuses % 2 == 0)  {
        return (1);
    } else {
        return (-1);
    }
}

static int check_alpha_before(char const *str)
{
    int i;
    int x;
    int nb = my_strlen(str);

    for (x = 0; x < nb; x++) {
        if (str[x] >= '0' && str[x] <= '9')
            break;
    }
    for (i = 0; i < nb; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            break;
        if ((str[i] >= 'A' && str[i] <= 'Z')
            || (str[i] >= 'a' && str[i] <= 'z'))
            break;
    }
    if (i == x)
        return (1);
    else
        return (0);
}

int my_getnbr(char const *str)
{
    int nb = my_strlen(str);
    int final = 0;
    int y = 0;
    int count = count_numbers(str, nb);
    int minus = minuses_or_plus(str, nb);
    int end = 0;

    for (int i = 0; i < nb && y != count; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            y = count_numbers(str, i + 1);
            final += (str[i] - 48) * my_compute_power_rec(10, count - y);
        }
    }
    final *= minus;
    if (check_alpha_before(str) == 0)
        final = 0;
    return (final);
}
