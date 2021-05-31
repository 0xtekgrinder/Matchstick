/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** task06
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int nb1 = my_strlen(s1);
    int nb2 = my_strlen(s2);

    for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
    if (i == nb2 && i == nb1)
        return (0);
    else if (s1[i] < s2[i])
        return (-1);
    else
        return (1);
}
