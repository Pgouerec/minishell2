/*
** EPITECH PROJECT, 2019
** # input.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

int parse_input(minishell_t *sh, char *input)
{
    char **input_parse = input_to_full_str_cmd(input);
    char **pipe_parse = cut_at_pipe_sign(input_parse);
    char **pipetmp = NULL;
    char **arg = NULL;

    for (int x = 0 ; pipe_parse[x] != NULL ; x++) {
        if (!pipe_parse[x])
            break;
        arg = str_to_arg_array(pipe_parse[x]);
        add_cmd(sh, arg[0], (my_arrlen(arg)), arg);
    }
    if (count_pipe(input_parse) > 1) {
        pipetmp = get_pipe_sign(input_parse);
        sh->pipe = my_arrdup(pipetmp);
        free_array(pipetmp);
    } else
        sh->pipe = NULL;
    free_array(pipe_parse);
    free_array(input_parse);
    return (0);
}

char **input_to_full_str_cmd(char *input)
{
    char **out = malloc(sizeof(char *) * (count_arg(input) + 1));
    char *tmp;
    int c = 0;
    int f = 0;
    int p = 0;
    int size = my_strlen(input);

    for (int x = 0 ; x < size ; x = c) {
        for (c = x ; input[c] != ' ' && input[c] != '\0' ; c++);
        tmp = malloc(sizeof(char) * ((c - x) + 2));
        f = 0;
        for (c = x ; input[c] != ' ' && input[c] != '\0' ; c++) {
            tmp[f] = input[c];
            f++;
            tmp[f] = '\0';
        }
        out[p] = my_strdup(tmp);
        free (tmp);
        p++;
        c++;
    }
    out[p] = NULL;
    return out;
}

char **cut_at_pipe_sign(char **input_array)
{
    char **out = malloc(sizeof(char *) * (count_pipe(input_array) + 1));
    char *tmp = NULL;
    int x = 0;
    int n = 0;

    for (; input_array[x] != NULL ; x++) {
        if (pipe_str(input_array[x]) == 0) {
            tmp = nw_str_cmd(tmp, input_array[x]);
        } else {
            out[n] = tmp;
            tmp = NULL;
            n++;
        }
    }
    out[n] = tmp;
    n++;
    out[n] = NULL;
    return (out);
}

char *nw_str_cmd(char *tmp, char *input)
{
    char *new_str = NULL;

    if (tmp == NULL) {
        tmp = my_strdup(input);
    } else {
        tmp = my_realloc(tmp, (my_strlen(input) + 3));
        tmp = my_cat(tmp, " ");
        tmp = my_cat(tmp, input);
    }
    new_str = my_strdup(tmp);
    free(tmp);
    return (new_str);
}

char **get_pipe_sign(char **input_array)
{
    char **out = malloc(sizeof(char *) * (count_pipe(input_array)));
    int x = 0;
    int n = 0;

    for (; input_array[x] != NULL ; x++) {
        if (pipe_str(input_array[x]) != 0) {
            out[n] = my_strdup(input_array[x]);
            n++;
        }
    }
    out[n] = NULL;
    return (out);
}