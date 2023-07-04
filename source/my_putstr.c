/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** my_putstr.c
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++){
        my_putchar(str[i]);
    }
}
