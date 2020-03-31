/*
** EPITECH PROJECT, 2019
** # minishell.h
** File description:
** header for minishell
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>

// Global
char **get_env(char **env);
int get_cmd(char **env);
char **route_cmd(char *line, char **env);
void printsh(char **env);
char *pwd_parse(char *pwd);
char **parse_args(char *av);
char **my_exit(char **av, char **env);
int detect_cmd(char *cmd);
int is_file_exist(char *path, char *cmd);
int is_folder_exist(char *path);
int count_double_array(char **arr);
char **my_str_to_arg_array(char *str);
int my_arrlen(char **arr);
char *env_name_cat(char **env, char *name, char *value);
void print_setenv_error(void);

// Env
char *get_env_value(char **env, char *name);
int get_env_line(char **env, char *name);
char *read_env_line(char **env, char *name, int line);
char **envpath_to_path(char *path);
char **set_env(char **av, char **env);
char **unset_env(char **av, char **env);
char **remove_env(char **env, char *str);
char **create_env(char **env, char *name, char *value);
char **create_empty_env(char **env, char *name);
char **edit_env(char **env, char *name, char *value);
char **edit_empty_env(char **env, char *name);
char **printenv(char **av, char **env);

// Signal
void sig_handler(int signum);

// exec
void pre_exec(char **av, char **env);
void exec_cmd(char **av, char **env, char **path, int x);

// cd
char **change_directory(char **av, char **env);
char *get_current_folder(void);
char **change_to_old(char **env);
char **change_to_other(char **env, char *path);

#endif