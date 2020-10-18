/*
** EPITECH PROJECT, 2019
** # minishell.h
** File description:
** header for minishell
*/

#ifndef MINISHELL2_H_
#define MINISHELL2_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <assert.h>
#include <fcntl.h>
#include <string.h>

// struct for multiple cmd prompt
typedef struct cmd_s
{
    char            *name;
    int             ac;
    char            **av;
    struct cmd_s    *next;
} cmd_t;

// control structure for cmd_s
typedef struct cmd_table_s
{
    cmd_t *first;
    cmd_t *last;
} cmd_table_t;

// strcut for env data
typedef struct env_line_s
{
    char *name;
    char *value;
    struct env_line_s *next;

} env_line_t;

typedef struct env_s
{
    env_line_t *first;
    env_line_t *last;
} env_t;

// global structure for env, path and cmd stockage
typedef struct global_s
{
    char **path;
    char **pipe;
    env_t       env;
    cmd_table_t cmd;
} minishell_t;

typedef struct pipe_sys_s
{
    int pfd[2];
    pid_t pid;
    char data[BUFSIZ];
    int nc;
    FILE *file;
} pipesys_t;

// initialisation
int init_global(minishell_t *global, char **env);
void cmd_table_init(cmd_table_t *cmd_table);
void env_table_init(env_t *env_table);

//path
int get_all_path(minishell_t *glb);
int path_parsing(char *path, minishell_t *global);
int count_path(char *path);
int get_all_path(minishell_t *glb);
int default_path(minishell_t *glb);

// free memory
int global_free(minishell_t *glb);
void delete_cmd_table(minishell_t *global);
int free_array(char **arr);

// prompt system
int prompt(minishell_t *global);
int verify_cmd(minishell_t *glb, char *line);

// cmd system
int add_cmd(minishell_t *global, char *name, int ac, char **av);
int parse_input(minishell_t *glb, char *input);
char **input_to_full_str_cmd(char *input);
char **cut_at_pipe_sign(char **input_array);
char **get_pipe_sign(char **input_array);
int pipe_str(char *src);
char **str_to_arg_array(char *input);
int count_arg(char *input);
int count_pipe(char **src);
char *nw_str_cmd(char *tmp, char *input);
int get_builtin_num(char *name);
int get_pipe_num(char *pipe);
int no_pipe_routing(minishell_t *glb);
int pipe_routing(minishell_t *sh);
void exec_simple_cmd_nofork(minishell_t *sh, cmd_t *cmd);

// redirection
int redirect_data(minishell_t *sh, cmd_t *cmd, pipesys_t *psys);
int create_file(pipesys_t *psys, cmd_t *cmd);
int create_file_append(pipesys_t *psys, cmd_t *cmd);
int right_simple(minishell_t *sh, cmd_t *cmd_a, cmd_t *cmd_b);
int right_double(minishell_t *sh, cmd_t *cmd_a, cmd_t *cmd_b);
int init_psys(pipesys_t *psys);
int left_simple(minishell_t *sh, cmd_t *cmd_a, cmd_t *cmd_b);
int left_double(minishell_t *sh, cmd_t *cmd_a, cmd_t *cmd_b);
int fn_pipe(minishell_t *sh, cmd_t *cmd_a, cmd_t *cmd_b);
int fn_semicolon(minishell_t *sh, int x, cmd_t *cmd_a, cmd_t *cmd_b);
int file_exist(cmd_t *cmd);

// env system
void delete_env_table(minishell_t *global);
int add_env_line(minishell_t *global, char *name, char *value);
int init_env(minishell_t *global, char **env);
int env_exist(char **env, int l);
char *env_name(char **env, int l);
char *env_value(char **env, int l);
char *get_env_value(minishell_t *global, char *name);
int env_exist_key(minishell_t *glb, char *name);
int env_delete_key(minishell_t *glb, char *name);
int env_add_key(minishell_t *glb, char *name, char *value);
void free_node_env(env_line_t *env);
void renew_path(minishell_t *glb);
char **env_to_array(minishell_t *glb);
int list_length(minishell_t *glb);

// shell
void advanced_prompt(void);

// cd system
char *get_current_folder(void);
int change_dir_any(minishell_t *glb, cmd_t *cmd);
char *create_path(char *dir);
int access_verification(cmd_t *cmd, char *path);
int access_verification_silent(char *path);
char *get_tild_user(cmd_t *cmd);
int change_dir_to_home(minishell_t *glb, char *cwd, char *home);
int change_dir_to_any_home(minishell_t *glb, cmd_t *cmd, char *cwd, char *home);
int change_dir_to_old(minishell_t *glb, cmd_t *cmd, char *cwd);
char *create_home_user_path(char *username);

// builtins
int print_env(minishell_t *global, cmd_t *cmd);
int my_setenv(minishell_t *glb, cmd_t *cmd);
int my_unsetenv(minishell_t *glb, cmd_t *cmd);
int change_dir(minishell_t *glb, cmd_t *cmd);

// utils
char **my_arr_realloc(char **origin, int size);
char **my_arrdup(char **origin);
int my_arrlen(char **arr);
char *my_clear_str(char *str);
int is_notprintable_char(char c);
char *word_array_to_str(char **arr);
char *my_strdup(char *src);
char *badchar_to_space(char *str);
char *if_empty(char *str);
char *my_cat(char *dest, char *src);
int my_isalphanum(char *name);

// exec
char *get_good_path(minishell_t *glb, cmd_t *cmd);
char *get_with_env_path(minishell_t *glb, cmd_t *cmd);
int cmd_exist_and_x_ok(char *command);
int cmd_file_exist(char *command);
void exec_simple_cmd(minishell_t *glb, cmd_t *cmd);
int exec_one_cmd(minishell_t *sh, cmd_t *cmd);

// output
void usage_too_many(cmd_t *cmd);
void usage_unknown_user(char *user);
void usage_alphanum_input(cmd_t *cmd);
void usage_not_dir(cmd_t *cmd);
void error_not_found(cmd_t *cmd);
void error_denied(cmd_t *cmd);
void error_exec_denied(cmd_t *cmd);
void error_no_such_file_o_dir(cmd_t *cmd);
void error_no_such_file_o_dir_bis(cmd_t *cmd);

// debug
void debug_cmd(cmd_t *cmd);
void debug_path(minishell_t *glb);
void debug_array(char *name, char **arr);

#endif