/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-adrien.audiard
** File description:
** bullet.c
*/

#include "../include/my_hunter.h"

int touched_by_bullet(moving_sprite_t *spr)
{
    if (my_strcmp(spr->name, "sprites/enemy.png") == 0) {
        set_sprite_p_v(spr, e_spwn_pos(), vectf(CTR_X, CTR_Y), 150);
        return 1;
    }
    if (my_strcmp(spr->name, "sprites/start.png") == 0 && spr->pos.y == 300)
        return 1;
    if (my_strcmp(spr->name, "sprites/resume.png") == 0 && spr->pos.y == 300)
        return 1;
    if (my_strcmp(spr->name, "sprites/exit.png") == 0 && spr->pos.x <= 701)
        return 1;
    if (my_strcmp(spr->name, "sprites/info.png") == 0 && spr->pos.x == 300) {
        print_info();
        return 1;
    }
    return 0;
}

int check_bullet_roll(list_sprite_t *bgn, sfSprite *bullet)
{
    int tch = 0;
    while (bgn != NULL) {
        if (on_sprite(sfSprite_getGlobalBounds(bgn->m_spt->spr), bullet)) {
            tch += touched_by_bullet(bgn->m_spt);
        }
        bgn = bgn->next;
    }
    return tch;
}

void check_all_bullet(sfRenderWindow *window, list_sprite_t *bullet,
    game_source_t *g_s, int *started)
{
    for (int tch = 0; bullet != NULL; tch = 0) {
        if (*started != 0 && bullet->m_spt->vect.x != 0 &&
            bullet->m_spt->vect.y != 0)
            tch += check_bullet_roll(g_s->g_spr[0], bullet->m_spt->spr);
        g_s->score += tch;
        if (check_bullet_roll(g_s->g_spr[1], bullet->m_spt->spr) != 0) {
            tch++;
            set_menu_box(g_s->g_spr, 1);
            (*started)++;
        }
        if (check_bullet_roll(g_s->g_spr[2], bullet->m_spt->spr))
            tch++;
        if (check_bullet_roll(g_s->g_spr[3], bullet->m_spt->spr))
            sfRenderWindow_close(window);
        tch += create_enemy(g_s->g_spr, bullet->m_spt->spr, *started);
        if (tch != 0)
            set_sprite_p_v(bullet->m_spt, vectf(CTR_X, CTR_Y),
            vectf(CTR_X, CTR_Y), 0);
        bullet = bullet->next;
    }
}
