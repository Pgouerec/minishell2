/*
** EPITECH PROJECT, 2019
** # signal_handler.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell.h"

void sig_handler(int signum)
{
    if (signum == 11)
        my_printf("\nSegmentation fault\n");
    exit (signum);
}