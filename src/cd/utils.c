/*
** EPITECH PROJECT, 2019
** # utils.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

char *create_path(char *dir)
{
    char *cwd = get_current_folder();
    char *path = NULL;
    int path_size = my_strlen(dir);

    if (dir[0] == '/') {
        path = my_strdup(dir);
    } else {    
        path = my_strdup(cwd);
        path = my_realloc(path, (path_size + 3));
        path = my_cat(path, "/");
        path = my_cat(path, dir);
    }
    free(cwd);
    return (path);
}

int access_verification(cmd_t *cmd, char *path)
{
    DIR* dir = NULL;
    dir = opendir(path);

    if (access(path, F_OK) == 0) {
        if (dir != NULL) {
            closedir(dir);
            return (0);
        } else {
            usage_not_dir(cmd);
            free(path);
            return (-1);
        }
    } else {
        error_no_such_file_o_dir(cmd);
        free(path);
        return (-1);
    }
    return (-1);
}

int access_verification_silent(char *path)
{
    if (access(path, F_OK) == 0) {
        if (access(path, R_OK) == 0) {
            return (0);
        } else {
            free(path);
            return (-1);
        }
    } else {
        free(path);
        return (-1);
    }
    return (-1);
}

char *get_tild_user(cmd_t *cmd)
{
    char *username = NULL;
    char *tmp = malloc(sizeof(char) * (my_strlen(cmd->av[1]) + 1));
    int n = 0;

    if (my_strcmp(cmd->av[1], "~") != 0) {
        for (int x = 1 ; cmd->av[1][x] != '\0' ; x++) {
            tmp[n] = cmd->av[1][x];
            n++;
        }
        tmp[n] = '\0';
        username = my_strdup(tmp);
        free(tmp);
        return (username);
    } else {
        free(tmp);
        return (NULL);
    }
}

char *create_home_user_path(char *username)
{
    char *home = my_strdup("/home/");
    char *path = NULL;
    int path_size = my_strlen(username);

    path = my_strdup(home);
    path = my_realloc(path, (path_size + 1));
    path = my_cat(path, username);
    free(home);
    return (path);
}