/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-adrien.audiard
** File description:
** return_x_y.c
*/

#include "../include/my_hunter.h"

int cmp_vectf(sfVector2f vect1, sfVector2f vect2, int prc)
{
    if (vect1.x - vect2.x < prc && vect1.x - vect2.x > -prc &&
        vect1.y - vect2.y < prc && vect1.y - vect2.y > -prc)
        return 1;
    return 0;
}

sfVector2f vectf(float x, float y)
{
    sfVector2f vector = {.x = x, .y = y};
    return vector;
}

sfVector2i vecti(int x, int y)
{
    sfVector2i vector = {.x = x, .y = y};
    return vector;
}
