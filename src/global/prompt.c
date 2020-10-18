/*
** EPITECH PROJECT, 2019
** # prompt.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

int prompt(minishell_t *sh)
{
    int rtn = 0;
    char *line = NULL;
    size_t len = 32;

    while (my_strcmp(line, "exit\n") != 0) {
        advanced_prompt();
        if (getline(&line, &len, stdin) != -1) {
            if (line[0] != '\n' && my_strcmp(line, "exit\n") != 0) {
                rtn = verify_cmd(sh, line);
            }
        } else {
            my_printf("exit\n");
            free(line);
            return (rtn);
        }
        delete_cmd_table(sh);
    }
    free(line);
    return rtn;
}

int verify_cmd(minishell_t *sh, char *line)
{
    char *cmd = NULL;
    int rtn = 0;

    cmd = my_clear_str(line);
    if (cmd != NULL && my_strlen(cmd) < 256) {
        parse_input(sh, cmd);
        if (sh->pipe != NULL) {
            rtn = pipe_routing(sh);
            free_array(sh->pipe);
        } else {
            rtn = no_pipe_routing(sh);
        }
        free(cmd);
    }
    return (rtn);
}