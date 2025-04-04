/*
** EPITECH PROJECT, 2024
** myls
** File description:
** my_strcmp
*/

#include "../../include/palindrome.h"

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return 1;
    }
    return 0;
}
