/*
** EPITECH PROJECT, 2019
** # clear_str_test.c
** File description:
** {description}
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "minishell2.h"

void redirect_all_std(void);

Test(clear_str, simple_str, .init = redirect_all_std)
{
    char str[] = "I'm a simple sentence without any bad characters !";

    my_printf("%s\n", my_clear_str(str));
    cr_assert_stdout_eq_str("I'm a simple sentence without any bad characters !\n", "");
}

Test(clear_str, tab_str, .init = redirect_all_std)
{
    char str[] = "I'm a\t\tsimple\tsentence.";

    my_printf("%s\n", my_clear_str(str));
    cr_assert_stdout_eq_str("I'm a simple sentence.\n", "");
}

Test(clear_str, tab_and_more_str, .init = redirect_all_std)
{
    char str[] = " I'm   a\t  \t  simple  \t   sentence.";

    my_printf("%s\n", my_clear_str(str));
    cr_assert_stdout_eq_str("I'm a simple sentence.\n", "");
}

Test(clear_str, complex_str, .init = redirect_all_std)
{
    char str[] = "  I'm   a\t  \t  simple  \t   sentence.    ";

    my_printf("%s\n", my_clear_str(str));
    cr_assert_stdout_eq_str("I'm a simple sentence.\n", "");
}