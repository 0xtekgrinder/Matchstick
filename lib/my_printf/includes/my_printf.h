/*
** EPITECH PROJECT, 2020
** my_printf.h
** File description:
** this is the header file for my_printf
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include <stdarg.h>

int my_printf(const char *str, ...);
void wrapper_porcentage(va_list ap, char *str);
void wrapper_show_str(va_list ap, char *str);
void wrapper_binary(va_list ap, char *str);
void wrapper_pointer(va_list ap, char *str);
void wrapper_hexadecimal(va_list ap, char *str);
void wrapper_hexadecimal_up(va_list ap, char *str);
void wrapper_unsigned_int(va_list ap, char *str);
void wrapper_string(va_list ap, char *str);
void wrapper_octal(va_list ap, char *str);
void wrapper_integrer(va_list ap, char *str);
void wrapper_character(va_list ap, char *str);
int my_putstr(char const *str);
int my_put_nbr(long long int nb);
void my_putchar(char c);
char *my_revstr(char *str);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_compute_power_rec(int nb, int power);
int my_getnbr(char const *str);
int my_intlen(long long int nb);
void str_change(char *str, int nb);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *src);
int my_put_unsigned_int(int nb);
void hexadecimal(unsigned int nb, int n);
void octal(int nb);

#endif /* !MY_PRINTF_H */