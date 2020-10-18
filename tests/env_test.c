/*
** EPITECH PROJECT, 2019
** # env_test.c
** File description:
** {description}
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "minishell2.h"

void redirect_all_std(void);

Test(environement, simple_duplication)
{
    global_t global;
    char *env[] = {"PATH=toto:tata:tutu:titi",
                    "PWD=test/test/test",
                    "NOTHING", NULL};

    env_dup(env, &global);
    for (int x = 0 ; env[x] != NULL ; x++) {
        cr_expect_eq(my_strcmp(env[x], global.env[x]), 0);
    }
}

Test(environement, simple_print_env, .init = redirect_all_std)
{
    global_t global;
    char *env[] = {"PATH=toto:tata:tutu:titi",
                    "PWD=test/test/test",
                    "NOTHING", NULL};

    env_dup(env, &global);
    env_print(&global);
    cr_assert_stdout_eq_str("PATH=toto:tata:tutu:titi\nPWD=test/test/test\nNOTHING\n", "");
}