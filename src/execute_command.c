/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** execute_command
*/

#include "../include/my.h"

int execute_command_for_real(char *path, char **commands, char **env)
{
    struct stat statbuf;

    stat(path, &statbuf);
    if (S_ISDIR(statbuf.st_mode) && execve(path, commands, env) == -1) {
        my_putstr_error(path);
        my_putstr_error(": Permission denied.\n");
        exit(1);
    }
    if (!S_ISDIR(statbuf.st_mode) && execve(path, commands, env) == -1) {
        my_putstr_error(path);
        my_putstr_error(": Command not found.\n");
        exit(1);
    }
    return 0;
}

int execute_commands(char *path, char **commands, char **env)
{
    pid_t pid = fork();
    int status = 0;

    if (pid == -1) {
        perror("fork");
        return 1;
    }
    if (pid == 0) {
        execute_command_for_real(path, commands, env);
    }
    waitpid(pid, &status, 0);
    if (WIFEXITED(status))
        return WEXITSTATUS(status);
    if (WTERMSIG(status) == SIGSEGV) {
        my_putstr_error("Segmentation fault (core dumped)\n");
        return 139;
    }
    return 1;
}
