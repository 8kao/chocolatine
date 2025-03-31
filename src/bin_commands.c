/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** bin_commands
*/

#include "../include/my.h"

char *find_path(char *cmd_to_find, char *direc, char *path)
{
    DIR *dir = opendir(direc);
    struct dirent *dr;

    if (!dir)
        return NULL;
    dr = readdir(dir);
    while (dr != NULL) {
        if (my_strcmp(dr->d_name, cmd_to_find) == 0) {
            path = direc;
            path = my_strcat(path, "/");
            path = my_strcat(path, cmd_to_find);
            closedir(dir);
            return path;
        }
        dr = readdir(dir);
    }
    closedir(dir);
    return NULL;
}

char *check_if_bin_command(char **env, char **commands, char *path)
{
    char *dir = NULL;
    char **eachdir = NULL;

    if (my_getenv_int(env, "PATH") == 84) {
        dir = "/home/mathilde/.cargo/bin:/usr/local/sbin:/usr/local/bin:/usr";
        dir = my_strcat(dir, "/sbin:/usr/bin:/sbin:/bin:/usr/games:");
        dir = my_strcat(dir, "/usr/local/games:/snap/bin:/snap/bin");
    } else
        dir = my_getenv(env, "PATH");
    if (!dir)
        return NULL;
    eachdir = my_str_to_word_array(dir, " =:");
    if (commands[0][0] == '/')
        return commands[0];
    for (int i = 0; eachdir[i]; i++) {
        path = find_path(commands[0], eachdir[i], path);
        if (path)
            return path;
    }
    return NULL;
}
