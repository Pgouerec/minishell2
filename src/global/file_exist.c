/*
** EPITECH PROJECT, 2019
** # file_exist.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell.h"

int is_file_exist(char *path, char *cmd)
{
    struct dirent *rd;
    DIR *dr;

    if (dr = opendir(path)) {
        for (int x = 0 ; rd = readdir(dr) ; x++) {
            if (my_strcmp(cmd, rd->d_name) == 0)
                return 0;
        }
    }
    return 1;
}

int is_folder_exist(char *path)
{
    char *folder = pwd_parse(path);
    struct dirent *rd;
    DIR *dr;

    if (dr = opendir(".")) {
        for (int x = 0 ; rd = readdir(dr) ; x++) {
            if (my_strcmp(folder, rd->d_name) == 0)
                return 0;
        }
    }
    return 1;
}