/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** cd_command
*/

#include "../include/my.h"

char **update_env_var(char **env, char *var, char *value)
{
    char **env_line;

    for (int i = 0; env[i]; i++) {
        env_line = my_str_to_word_array(env[i], " =");
        if (my_strcmp(var, env_line[0]) == 0) {
            env[i] = "OLDPWD=";
            env[i] = my_strcat(env[i], value);
            return env;
        }
        free_array(env_line);
    }
    return env;
}

int change_directory(char *dir, char **env, char *cwd)
{
    if (dir == NULL || my_strcmp(dir, "~") == 0)
        return chdir(my_getenv(env, "HOME"));
    if (my_strcmp(dir, "-") == 0)
        return chdir(my_getenv(env, "OLDPWD"));
    if (chdir(dir) == -1) {
        my_putstr_error(dir);
        my_putstr_error(": Not a directory.\n");
        return -1;
    }
    return 0;
}

int cd_command(char **commands, char **env)
{
    char cwd[1000];
    char *dir = commands[1];

    getcwd(cwd, sizeof(cwd));
    env = update_env_var(env, "PWD", cwd);
    if (change_directory(dir, env, cwd) == -1)
        return 1;
    env = update_env_var(env, "OLDPWD", cwd);
    getcwd(cwd, sizeof(cwd));
    env = update_env_var(env, "PWD", cwd);
    return 0;
}
