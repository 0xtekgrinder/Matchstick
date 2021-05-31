/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** task07
*/

int my_strlen(char const *str);

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (i = 0; s1[i] == s2[i] && i < n; i++);
    if (i == n)
        return (0);
    else if (s1[i] < s2[i])
        return (-1);
    else
        return (1);
}
