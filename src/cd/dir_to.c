/*
** EPITECH PROJECT, 2019
** # dir_to.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

int change_dir_to_old(minishell_t *sh, cmd_t *cmd, char *cwd)
{
    char *tmp = get_env_value(sh, "OLDPWD");
    char *oldpwd = NULL;

    if (tmp == NULL)
        oldpwd = get_current_folder();
    else {
        oldpwd = my_strdup(tmp);
    }
    if (my_strcmp(cmd->av[1], "-") != 0) {
        my_printf("Usage: cd [-|<dir>].\n");
        free(oldpwd);
    } else {
        chdir(oldpwd);
        env_add_key(sh, my_strdup("OLDPWD"), my_strdup(cwd));
        env_add_key(sh, my_strdup("PWD"), my_strdup(oldpwd));
        free(oldpwd);
    }
    return (0);
}

int change_dir_to_home(minishell_t *sh, char *cwd, char *home)
{
    env_add_key(sh, my_strdup("OLDPWD"), my_strdup(cwd));
    env_add_key(sh, my_strdup("PWD"), my_strdup(home));
    chdir(home);
    return (0);
}

int change_dir_to_any_home(minishell_t *sh, cmd_t *cmd, char *cwd, char *home)
{
    char *username = get_tild_user(cmd);
    char *userpath = NULL;

    if (username) {
        userpath = create_home_user_path(username);
        if (access_verification_silent(userpath) != 0) {
            usage_unknown_user(username);
        } else {
            env_add_key(sh, my_strdup("OLDPWD"), my_strdup(cwd));
            env_add_key(sh, my_strdup("PWD"), my_strdup(userpath));
            chdir(userpath);
            free(userpath);
        }
        free(username);
    } else {
        change_dir_to_home(sh, cwd, home);
    }
    return (0);   
}