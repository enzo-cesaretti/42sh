/*
** EPITECH PROJECT, 2023
** SH_CD
** File description:
** BUILTIN COMMAND
*/

#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void my_puterr_cd(char *file)
{
    my_puterr(file);
    my_puterr(": ");
    my_puterr(strerror(errno));
    my_puterr(".\n");
}

void cd_tidle(char **args, char *last_dir, gll_t *env)
{
    getcwd(last_dir, FILENAME_MAX + 1);
    char *home_path = get_env(env, "HOME");
    if (chdir(home_path) != 0) perror(args[1]);
    free(home_path);
}

void cd_sub(char *last_dir, char *tmp)
{
    my_strcpy(tmp, last_dir);
    getcwd(last_dir, FILENAME_MAX + 1);
    if (chdir(tmp) != 0)
        my_puterr(": No such file or directory\n");
}

int sh_cd(char **args, gll_t *env)
{
    static char last_dir[FILENAME_MAX];
    char tmp[FILENAME_MAX];
    if (!args[1] || my_strcmp(args[1], "~") || my_strcmp(args[1], "home")) {
        if (args[1] && my_strcmp(args[1], "home"))
            my_putstr("~\n");
        cd_tidle(args, last_dir, env);
    } else if (my_strcmp(args[1], "-")) {
        cd_sub(last_dir, tmp);
    } else {
        getcwd(last_dir, FILENAME_MAX + 1);
        if (chdir(args[1]) != 0)
            my_puterr_cd(args[1]);
    }
    env = sh_update_env("PWD", getcwd(NULL, FILENAME_MAX + 1), env);
    return 1;
}
