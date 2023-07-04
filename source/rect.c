/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-adrien.audiard
** File description:
** rect.c
*/

#include "../include/my_hunter.h"

void set_rect(moving_sprite_t *spr, int width, int height, sfVector2i offset)
{
    spr->rect.left = offset.x;
    spr->rect.top = offset.y;
    spr->rect.width = width;
    spr->rect.height = height;
    sfSprite_setOrigin(spr->spr,
        vectf(spr->rect.width / 2, spr->rect.height / 2));
}

void set_all_rect(list_sprite_t **all_s)
{
    set_rect(all_s[0]->m_spt, all_s[0]->m_spt->wdt, all_s[0]->m_spt->hgt,
        vecti(0, 0));
    set_rect(all_s[1]->m_spt, all_s[1]->m_spt->wdt, all_s[1]->m_spt->hgt,
        vecti(0, 0));
    set_rect(all_s[2]->m_spt, all_s[2]->m_spt->wdt, all_s[2]->m_spt->hgt,
        vecti(0, 0));
    set_rect(all_s[3]->m_spt, all_s[3]->m_spt->wdt, all_s[3]->m_spt->hgt,
        vecti(0, 0));
    set_rect(all_s[5]->m_spt, 57, all_s[5]->m_spt->hgt, vecti(0, 0));
}
