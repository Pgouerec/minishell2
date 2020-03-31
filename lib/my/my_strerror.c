/*
** EPITECH PROJECT, 2019
** # my_strerror.c
** File description:
** {description}
*/

#include <stdio.h>
#include <errno.h>
#include "my.h"

void my_strerror(int err)
{
    char buff[1024];

    if (0 <= err && sys_errlist[err]) {
        my_puterror(sys_errlist[err]);
    } else {
        my_puterror("Unknown error : ");
        my_putnbr(err);
    }
}