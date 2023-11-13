/*
** EPITECH PROJECT, 2023
** SHELL
** File description:
** SHELL
*/

#ifndef SHELL
    #define SHELL
    #define STRTOK_DELIM " \t\r\n\a"
    #include "gll.h"
    #define MAX_ARGS 100
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

enum andor_e {
    AND,
    OR_P
};

typedef struct shell_s {
    gll_t *env;
    gll_t *var;
    char *input;
    char *hist_cmd;
    char *tokens;
    char **args;
    char **cmds;
    int exit_status;
    enum andor_e cmd_type;
} shell_t;

typedef struct andor_s {
    enum andor_e type;
    char *cmd;
} andor_t;

void my_putchar(char c);
void my_putstr(const char *str);
void my_puterr(const char *str);
void my_put_nbr(int nb);
int my_strlen(const char *str);
int my_printf(const char *format, ...);

int my_isspace(int c);
int my_isalpha(int c);

int print_strtab(char **tab);
int len_strtab(char **tab);
char **dup_strtab(char **tab);
void free_strtab(char **tab);

bool my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char *str);
char *my_strstr(char *haystack, char *needle);

bool my_isalnum(char c);

void gll_unset(gll_t *list, char *key);

char **gll_to_array(gll_t *list);
gll_t *array_to_gll(char **array);

bool is_exist(char *entry, char *key);
int get_len_args(char **args);
int sh_num_builtins(void);
bool sh_is_builtins(char *build);

bool check_value(char *key);

int sh_cd(char **args, gll_t *env);
int sh_help(char **args, gll_t *env);
int sh_env(char **args, gll_t *env);
int sh_setenv(char **args, gll_t *env);
int sh_unsetenv(char **args, gll_t *env);
int sh_exit(char **args, gll_t *env);

int history(char **args, gll_t *env);
void add_history(char *input, gll_t *env);
void handle_arrow(char *input, gll_t *env);

void sh_loop(char **r_env);
char **sh_parser(char *input, char *sep);

int sh_execute_builtin(shell_t *sh, char **args);
int sh_execute(shell_t *sh, char **args);
int sh_pipe_exec(shell_t *sh, char **args, int fd, int idx);
int wait_child_death(int wstatus, int pipe_fd[2]);

char *tokenize(char *input);
void free_all(char **args, char *tokens);

gll_t *sh_create_env(char **r_env);
gll_t *sh_update_env(char *key, char *value, gll_t *env);

bool comp_for_linux(char *filepath);

char *search_cmd(char **paths, char *cmd);
char *find_cmd(char *cmd, gll_t *env);
char *get_home(gll_t *env);
char *get_path(gll_t *env);
char *get_env(gll_t *env, char *key);
void set_env(gll_t *env, char *key, char *value);

void handle_signal(int status);

char **double_redirection_right_out(char **redir);
char **simple_redirection_right_out(char **redir);
char **simple_redirection_right_in(char **redir);

char **select_redir(char *cmd);
int handle_cmd(shell_t *sh);

void redirect_in(char *filename);
void redirect_out(char *filename);
void double_redirect_out(char *filename);

int is_valid_pipe_command(char *command);
bool pipe_syntaxe_error(char *tokens);
int is_valid_redir_command(char *cmd);
bool redir_syntaxe_error(char *tokens);

char *trim(char *s);

void print_prompt(shell_t *sh);

gll_t *parse_andor(char *str);
int handle_andor(shell_t *sh);

char *get_hist_line(shell_t *sh, int line);
char *concat(char *str, char *suffix);
int handle_history(shell_t *sh);

void free_sh(shell_t *sh);

int is_file(const char *dirpath);
bool dir_err(const char *filepath, char **args);

#endif /* !SHELL */
