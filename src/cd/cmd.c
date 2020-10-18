/*
** EPITECH PROJECT, 2019
** # cmd.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

char *get_current_folder(void)
{
    char str[1024];
    char *cwd = NULL;

    getcwd(str, sizeof(str));
    cwd = my_strdup(str);
    return cwd;
}

int change_dir(minishell_t *sh, cmd_t *cmd)
{
    char *home = my_strdup(get_env_value(sh, "HOME"));
    char *cwd = get_current_folder();

    if (!home)
        return (-1);
    if (cmd->ac > 2) {
        usage_too_many(cmd);
        return (0);
    }
    if (cmd->ac < 2) {
        change_dir_to_home(sh, cwd, home);
    } else if (cmd->ac == 2 && cmd->av[1][0] == '~') {
        change_dir_to_any_home(sh, cmd, cwd, home);
    } else if ((cmd->ac == 2 && cmd->av[1][0] == '-')) {
        change_dir_to_old(sh, cmd, cwd);
    } else
        change_dir_any(sh, cmd);
    free(cwd);
    free(home);
    return (0);
}

int change_dir_any(minishell_t *sh, cmd_t *cmd)
{
    char *cwd = get_current_folder();
    char *newcwd = NULL;
    char *path = create_path(cmd->av[1]);

    if (access_verification(cmd, path) != 0) {
        return (-1);
    }
    env_add_key(sh, my_strdup("OLDPWD"), my_strdup(cwd));
    chdir(path);
    newcwd = get_current_folder();
    env_add_key(sh, my_strdup("PWD"), my_strdup(cwd));
    free(cwd);
    free(newcwd);
    free(path);
    return (0);
}