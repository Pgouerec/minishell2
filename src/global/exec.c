/*
** EPITECH PROJECT, 2019
** # exec.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell.h"

char **route_cmd(char *line, char **env)
{
    char **(*my_cmd[])(char **av, char **env) = {change_directory, my_exit,
                                                printenv, set_env, unset_env};
    char **av = parse_args(line);
    int is_cmd = detect_cmd(av[0]);

    if (is_cmd != -1)
        env = my_cmd[is_cmd](av, env);
    else
        pre_exec(av, env);
    return env;
}

void exec_cmd(char **av, char **env, char **path, int x)
{
    int len = my_strlen(av[0]);
    pid_t pid;
    char *fullpath = malloc(sizeof(char) * my_strlen(path[x]) + len);

    fullpath = my_strcat(path[x], av[0]);
    if (pid = fork()) {
        waitpid(pid, NULL, 0);
        return;
    }
    if (execve(fullpath, av, env) == -1) {
        perror("execve");
        exit (0);
    }
}

void pre_exec(char **av, char **env)
{
    char *envpath = get_env_value(env, "PATH");
    char **path;
    int max = 0;
    int x = 0;

    if (envpath != NULL) {
        path = envpath_to_path(envpath);
        max = count_double_array(path);
        for (x ; path[x] != NULL ; x++) {
            if (is_file_exist(path[x], av[0]) == 0) {
                exec_cmd(av, env, path, x);
                break;
            }
        }
        if (x >= max) {
            my_printf("%s: Command not found.\n", av[0]);
        }
    }
}
