/*
** EPITECH PROJECT, 2025
** my
** File description:
** oui
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/wait.h>
    #include <stdio.h>
    #include <string.h>
    #include <sys/types.h>
    #include <dirent.h>
    #include <string.h>
    #include <errno.h>
    #include <sys/stat.h>
    #include <signal.h>


//Src
int cd_command(char **commands, char **env);
int execute_commands(char *path, char **commands, char **env);
int check_if_env_command(char **commands, char **env);
char *check_if_bin_command(char **env, char **commands, char *path);
char *find_path(char *cmd_to_find, char *direc, char *path);
char *my_getenv(char **env, char *tofind);
char **update_env_var(char **env, char *var, char *value);
int my_getenv_int(char **env, char *tofind);

//Lib
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_atoi(char *str);
int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
char **my_str_to_word_array(const char *str, const char *reject);
int my_isalnum(char c);
char *my_strcat(char *str, char *addstr);
int my_strlen(char const *str);
size_t my_strcspn(const char *str, const char *reject);
char *my_strcpy(char *dest, char const *src);
int my_putstr_error(char const *str);
int free_array(char **array);


#endif /* !MY_H_ */
