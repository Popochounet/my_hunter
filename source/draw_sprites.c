/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-adrien.audiard
** File description:
** draw_sprites.c
*/

#include "../include/my_hunter.h"

void draw_list_sprite(sfRenderWindow *window, list_sprite_t *begin)
{
    while (begin != NULL) {
        sfSprite_setPosition(begin->m_spt->spr, begin->m_spt->pos);
        sfSprite_setTextureRect(begin->m_spt->spr, begin->m_spt->rect);
        sfRenderWindow_drawSprite(window, begin->m_spt->spr, NULL);
        begin = begin->next;
    }
}

void draw_all_sprites(sfRenderWindow *window, list_sprite_t **all_s)
{
    for (int i = 0; i < NB_SPRITE; i++) {
        draw_list_sprite(window, all_s[i]);
    }
}
