/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday06-adrien.audiard
** File description:
** my_strcmp.c
*/

#include "../include/my_hunter.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i;
    for (i = 0; s1[i] != '\0' && s1[i] == s2[i]; i++) {
    }
    if (s1[i] == '\0' && s2[i] == '\0')
        return 0;
    if (s1[i] > s2[i])
        return 1;
    return -1;
}
