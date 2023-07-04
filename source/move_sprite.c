/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-adrien.audiard
** File description:
** enemy_spawn.c
*/

#include "../include/my_hunter.h"

void start_sprite_move(moving_sprite_t *spr)
{
    spr->vect.x = (spr->dir.x - spr->pos_ini.x) / spr->speed;
    spr->vect.y = (spr->dir.y - spr->pos_ini.y) / spr->speed;
}

void stop_sprite_move(moving_sprite_t *spr)
{
    spr->vect.x = 0;
    spr->vect.y = 0;
}

void stop_if(moving_sprite_t *spr)
{
    if (cmp_vectf(spr->pos, spr->dir, 5))
        stop_sprite_move(spr);

}

void move_sprite(moving_sprite_t *spr)
{
    spr->pos.x += spr->vect.x;
    spr->pos.y += spr->vect.y;
}
