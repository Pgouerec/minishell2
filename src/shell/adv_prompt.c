/*
** EPITECH PROJECT, 2019
** # adv_prompt.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

void advanced_prompt(void)
{
    char *cwd = NULL;

    cwd = get_current_folder();
    my_printf("[%s]$> ", cwd);
    free(cwd);
}