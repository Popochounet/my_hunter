/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-adrien.audiard
** File description:
** destroy.c
*/

#include "../include/my_hunter.h"

void destroy_sprite(moving_sprite_t *m_spr)
{
    sfSprite_destroy(m_spr->spr);
    sfTexture_destroy(m_spr->tx);
    free(m_spr->name);
}

void destroy_all(game_source_t *g_src, sfClock *m_clock, sfRenderWindow *wd)
{
    sfClock_destroy(m_clock);
    sfRenderWindow_destroy(wd);
    roll_all_sprites(g_src->g_spr, &destroy_sprite);
    for (int i = 0; i < NB_SPRITE; i++) {
        free(g_src->g_spr[i]);
    }
    free(g_src->g_spr);
    for (int i = 0; i < NB_SOUND; i++) {
        sfSound_destroy(g_src->g_sound->sound);
        sfSoundBuffer_destroy(g_src->g_sound->s_buf);
    }
    free(g_src->g_sound);
}
