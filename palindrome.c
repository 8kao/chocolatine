/*
** EPITECH PROJECT, 2024
** palindrome
** File description:
** ok
*/

#include "include/palindrome.h"

int palindrome(char *str)
{
    char *backwstr = str;
    int len = my_strlen(str) - 1;

    for (int i = 0; str[i] != '\0' && backwstr[len] > 0; i++) {
        if (str[i] != backwstr[len] && str[i] + 32 != backwstr[len]
        && str[i] - 32 != backwstr[len])
            return 1;
        len--;
    }
    return 0;
}

int main(int ac, char **argv)
{
    if (ac < 2 || ac > 2) {
        write(2, "Error: missing arguments.\n", 26);
        return 84;
    }
    if (palindrome(argv[1]) == 0) {
        write(1, "palindrome!\n", 12);
        return 0;
    } else if (palindrome(argv[1]) == 1) {
        write(1, "not a palindrome.\n", 18);
        return 0;
    }
}
