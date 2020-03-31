/*
** EPITECH PROJECT, 2019
** # standard_test.c
** File description:
** {description}
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}