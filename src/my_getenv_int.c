/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** my_getenv
*/

#include "../include/my.h"

int my_getenv_int(char **env, char *tofind)
{
    char **env_line;

    for (int i = 0; env[i]; i++) {
        env_line = my_str_to_word_array(env[i], " =");
        if (my_strcmp(env_line[0], tofind) == 0)
            return 0;
    }
    return 84;
}
