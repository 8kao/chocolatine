/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** env
*/

#include "../include/my.h"


static int check_char_in_variable(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (my_isalnum(str[i]) == 1) {
            return 1;
        }
    }
    return 0;
}

static int display_env(char **env)
{
    for (int i = 0; env[i]; i++) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
    return 0;
}

void next_line_not_empty(char **env, int pos)
{
    for (int i = pos; env[i]; i++) {
        env[i] = env[i + 1];
    }
}

int delete_in_env(char **commands, char **env)
{
    char **env_line;
    int i = 0;

    if (!commands[1]) {
        my_putstr_error("unsetenv: Too few arguments.\n");
        return 84;
    }
    for (; env[i]; i++) {
        env_line = my_str_to_word_array(env[i], " =");
        if (my_strcmp(commands[1], env_line[0]) == 0) {
            next_line_not_empty(env, i);
            return 0;
        }
        free_array(env_line);
    }
    return 0;
}

char *add_new_variable(char *str, char **commands)
{
    str = malloc(sizeof(char) * my_strlen(commands[1]));
    str = commands[1];
    str = my_strcat(str, "=");
    if (commands[2])
        str = my_strcat(str, commands[2]);
    else
        str = my_strcat(str, "\0");
    return str;
}

static char *replace_new_varibale(char *str, char **commands)
{
    char *nothing = "\0";

    str = malloc(sizeof(char) * my_strlen(commands[1]));
    str = commands[1];
    str = my_strcat(str, "=");
    if (!commands[2])
        commands[2] = nothing;
    str = my_strcat(str, commands[2]);
    return str;
}

static int my_tablen(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    return i;
}

static int error_cases(char **commands)
{
    int len = my_tablen(commands);

    if (len > 3) {
        my_putstr_error("setenv: Too many arguments.\n");
        return 84;
    }
    if (my_isalnum(commands[1][0])) {
        my_putstr_error("setenv: Variable name must begin with a letter.\n");
        return 84;
    }
    if (check_char_in_variable(commands[1]) == 1) {
        my_putstr_error(
        "setenv: Variable name must contain alphanumeric characters.\n");
        return 84;
    }
    return 0;
}

int parse_in_env(char **commands, char **env)
{
    int int_count = 0;
    char **env_line;

    if (!commands[1])
        return display_env(env);
    if (error_cases(commands) == 84)
        return 84;
    for (int i = 0; env[i]; i++) {
        env_line = my_str_to_word_array(env[i], " =");
        if (my_strcmp(commands[1], env_line[0]) == 0) {
            env[i] = replace_new_varibale(env[i], commands);
            return 0;
        }
        int_count++;
        free_array(env_line);
    }
    env[int_count] = add_new_variable(env[int_count], commands);
    env[int_count + 1] = NULL;
    return 0;
}

int check_if_env_command(char **commands, char **env)
{
    if (my_strcmp(commands[0], "env") == 0) {
        display_env(env);
        return 0;
    }
    if (my_strcmp(commands[0], "unsetenv") == 0) {
        delete_in_env(commands, env);
        return 0;
    }
    if (my_strcmp(commands[0], "setenv") == 0) {
        parse_in_env(commands, env);
        return 0;
    }
}
