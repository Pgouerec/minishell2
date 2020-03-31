/*
** EPITECH PROJECT, 2019
** # read_cmd.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell.h"

int get_cmd(char **env)
{
    char *line = NULL;
    size_t len = 32;

    while (line != "exit\n") {
        printsh(env);
        signal(SIGINT, sig_handler);
        signal(SIGSEGV, sig_handler);
        if (getline(&line, &len, stdin) != -1) {
            if (line[0] != '\n')
                env = route_cmd(line, env);
        } else {
            my_printf("exit\n");
            break;
        }
    }
    return 0;
}