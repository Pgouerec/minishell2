/*
** EPITECH PROJECT, 2019
** # myheader.h
** File description:
** my super duper header.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>

void my_putchar(char x);
void my_swap(int *a, int *b);
int my_isneg(int nb);
int my_putnbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_getnbr(char const *str);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strstr(char *sstr, char const *to_find);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_revstr(char *str);
char *my_getchar(char const *str);
int my_puterror(char const *str);
void my_putdstr(char **str);
char *my_realloc(char *str, int size);
char *my_dec_to_oct(long dec);
char *my_dec_to_bin(long dec);
char *my_dec_to_hex(long dec, int size);
void my_strerror(int err);
char **my_str_to_word_array(char *str);
int count_word(char *input);
int is_alphanum(char const *str);

int my_printf(char *s, ...);
void disp_int(char *s, va_list args);
void disp_chr(char *s, va_list args);
void disp_str(char *s, va_list args);
void disp_uint(char *s, va_list args);
void disp_astr(char *s, va_list args);
void disp_dstr(char *s, va_list args);
void disp_oct(char *s, va_list args);
void disp_bin(char *s, va_list args);
void disp_hexs(char *s, va_list args);
void disp_hexh(char *s, va_list args);
void disp_prcnt(char *s, va_list args);
void disp_errno(char *s, va_list args);

int sum_stdarg(int i, int nb, ...);
int disp_stdarg(char *s, ...);

void my_sort_int_array(int *tab, int size);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_isupper(char const *str);
int my_str_islower(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);

#endif
