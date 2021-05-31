/*
** EPITECH PROJECT, 2020
** my_strcapitalize
** File description:
** task10
*/

int my_strlen(char const *str);

char *my_strlowcase(char *str);

static int my_char_isalpha(char str)
{
    if ((str >= 'A' && str <= 'Z') || (str >= 'a' && str <= 'z')
        || (str >= '0' && str <= '9'))
        return (0);
    else
        return (1);
}

char *my_strcapitalize(char *str)
{
    my_strlowcase(str);
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] -= 32;
    for (int i = 0; str[i]; i++) {
        if (my_char_isalpha(str[i]) == 1) {
            if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
                str[i + 1] -= 32;
        }
    }
    return (str);
}
