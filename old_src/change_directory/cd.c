/*
** EPITECH PROJECT, 2019
** # cd.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell.h"

char *get_current_folder(void)
{
    char str[1024];
    char *cwd;

    getcwd(str, sizeof(str));

    cwd = malloc(sizeof(char) * my_strlen(str));
    cwd = str;
    return cwd;
}

char **change_directory(char **av, char **env)
{
    char *home = get_env_value(env, "HOME");
    char *cwd = get_current_folder();

    if (av[1] == NULL) {
        env = edit_env(env, "OLDPWD", cwd);
        env = edit_env(env, "PWD", home);
        chdir(home);
    } else if (my_strcmp(av[1], "~") == 0) {
        env = edit_env(env, "OLDPWD", cwd);
        env = edit_env(env, "PWD", home);
        chdir(home);
    } else {
        if (my_strlen(av[1]) == 1 && av[1][0] == '-')
            env = change_to_old(env);
        else
            env = change_to_other(env, av[1]);
    }

    return env;
}

char **change_to_old(char **env)
{
    char *oldpwd = get_env_value(env, "OLDPWD");
    char *home = get_env_value(env, "HOME");
    char *cwd = get_current_folder();
    
    if (oldpwd == NULL)
        if (home != NULL)
            oldpwd = home;
        else
            oldpwd = "/";
    env = edit_env(env, "OLDPWD", cwd);
    env = edit_env(env, "PWD", oldpwd);
    chdir(oldpwd);
    return env;
}

char **change_to_other(char **env, char *path)
{
    char *cwd = get_current_folder();
    char *fullpath = my_strcat(cwd, "/");

    fullpath = my_strcat(fullpath, path);

    if (access(fullpath, F_OK) != -1 || is_folder_exist(fullpath) == 0) {
        env = edit_env(env, "OLDPWD", cwd);
        chdir(fullpath);
        cwd = get_current_folder();
        env = edit_env(env, "PWD", cwd);
    } else {
        my_printf("%s: No such file or directory.\n", path);
    }
    return env;
}