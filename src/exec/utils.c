/*
** EPITECH PROJECT, 2019
** # utils.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

char *get_good_path(minishell_t *sh, cmd_t *cmd)
{
    char *newpath = get_with_env_path(sh, cmd);

    if (cmd_exist_and_x_ok(newpath) == 1) {
        error_not_found(cmd);
        free(newpath);
        return (NULL);
    } else if (cmd_exist_and_x_ok(newpath) == 2) {
        error_exec_denied(cmd);
        free(newpath);
        return (NULL);
    } else {
        return (newpath);
    }
    return (NULL);
}

char *get_with_env_path(minishell_t *sh, cmd_t *cmd)
{
    char *newpath = NULL;
    int x = 0;

    if (cmd->name[0] == '.' && cmd->name[1] == '/')
        return my_strdup(cmd->name);
    if (cmd->name[0] == '/') {
        newpath = my_strdup(cmd->name);
        return (newpath);
    }
    for (; sh->path[x] != NULL ; x++) {
        newpath = my_strdup(sh->path[x]);
        newpath = my_realloc(newpath, my_strlen(cmd->name) + 2);
        newpath = my_cat(newpath,"/");
        newpath = my_cat(newpath, cmd->name);
        if (cmd_file_exist(newpath) == 0) {
            break;
        }
    }
    return (newpath);
}

int cmd_file_exist(char *command)
{
    if (access(command, F_OK) == 0) {
        return (0);
    } else {
        return (1);
    }
    return (-1);
}

int cmd_exist_and_x_ok(char *command)
{
    if (access(command, F_OK) == 0) {
        if (access(command, X_OK) == 0) {
            return (0);
        } else {
            return (2);
        }
    } else {
        return (1);
    }
    return (-1);
}