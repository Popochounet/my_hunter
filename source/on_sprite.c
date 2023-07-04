/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-adrien.audiard
** File description:
** on_screen.c
*/

#include "../include/my_hunter.h"

int on_sprite(sfFloatRect contain_bd, sfSprite *spr_on)
{
    sfFloatRect spr_bd = sfSprite_getGlobalBounds(spr_on);
    spr_bd.width += spr_bd.left;
    spr_bd.height += spr_bd.top;
    int ct = 0;
    ct += sfFloatRect_contains(&contain_bd, spr_bd.left, spr_bd.top);
    ct += sfFloatRect_contains(&contain_bd, spr_bd.width, spr_bd.top);
    ct += sfFloatRect_contains(&contain_bd, spr_bd.left, spr_bd.height);
    ct += sfFloatRect_contains(&contain_bd, spr_bd.width, spr_bd.height);
    return ct == 0 ? 0 : 1;
}

int on_screen_roll(list_sprite_t *bgn)
{
    sfFloatRect wd_bound = {.left = 0, .width = WD_WIDTH,
        .top = 0, .height = WD_HEIGHT};
    int spr_on_screen = 0;
    while (bgn != NULL) {
        spr_on_screen += on_sprite(wd_bound, bgn->m_spt->spr);
        bgn = bgn->next;
    }
    return spr_on_screen;
}

int on_sprite_roll(sfSprite *spr, list_sprite_t *bgn)
{
    int spr_on_sprite = 0;
    while (bgn != NULL) {
        spr_on_sprite += on_sprite(sfSprite_getGlobalBounds(spr),
            bgn->m_spt->spr);
        bgn = bgn->next;
    }
    return spr_on_sprite;
}
