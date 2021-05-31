/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** task02
*/

#ifndef MY_H_
#define MY_H_

#include <stddef.h>

char *int_to_str(int nb, char *str);
void *my_realloc(char *ptr, size_t size);
int my_intlen(int nb);
void my_free(char *list, ...);
char **my_tabdup(char **tab);
void my_put_error(char const *str);
char **tab_malloc(int rows, int cols);
void *my_memset(void *s, int c, size_t n);
void my_putchar(char c);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
int my_show_word_array(char **tab);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
char *read_file(char *file_name);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
char *my_str_create(char *str, int start_offset, int end_offset);
int my_printf(const char *str, ...);
int my_tablen(char **tab);
char **my_str_to_word_array(char const *str);

#endif /* MY_H_ */
