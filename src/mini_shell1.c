/*
** EPITECH PROJECT, 2025
** bsminishell1
** File description:
** mini_shell1
*/

#include "../include/my.h"

int check_builtin_commands(char **commands, char **env)
{
    if (my_strcmp(commands[0], "cd") == 0) {
        cd_command(commands, env);
        return 0;
    }
    return 1;
}

int parse_args(char *buffer, char **env)
{
    char **commands = my_str_to_word_array(buffer, " \t");
    char *path = NULL;
    int exec_status = 0;

    if (check_builtin_commands(commands, env) == 0)
        return 0;
    if (check_if_env_command(commands, env) == 0)
        return 0;
    path = check_if_bin_command(env, commands, path);
    if (!path)
        path = commands[0];
    exec_status = execute_commands(path, commands, env);
    return exec_status;
}

static int while_conditions(char *buffer, char **env)
{
    int codereturn = 0;

    if (buffer[0] == '\n')
        return 0;
    buffer[my_strcspn(buffer, "\n")] = '\0';
    if (my_strcmp(buffer, "exit") == 0) {
        free(buffer);
        return 1;
    }
    codereturn = parse_args(buffer, env);
    if (codereturn != 0) {
        return codereturn;
    }
    return 0;
}

static void display_prompt(char **env)
{
    char *user = my_getenv(env, "USER");
    char cwd[1000];

    user = my_strcat(user, "@");
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        write(1, "\033[0;32m", my_strlen("\033[0;32m"));
        write(1, user, my_strlen(user));
        write(1, "\033[0;36m", my_strlen("\033[0;36m"));
        write(1, cwd, my_strlen(cwd));
        write(1, "> ", 2);
        write(1, "\033[0m", my_strlen("\033[0m"));
    }
}

int main(int ac, char **argv, char **env)
{
    char *buffer = NULL;
    size_t len = 0;
    char cwd[1000];
    int codereturn = 0;

    while (1) {
        if (isatty(0) == 1)
            display_prompt(env);
        if (getline(&buffer, &len, stdin) == -1) {
            break;
        }
        codereturn = while_conditions(buffer, env);
        if (codereturn != 0)
            return codereturn;
    }
    free(buffer);
    return 0;
}
