/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-adrien.audiard
** File description:
** manage_mouse_click.c
*/

#include "../include/my_hunter.h"

int is_sprite_clicked(sfSprite *spr, sfVector2f coord)
{
    sfFloatRect bound = sfSprite_getGlobalBounds(spr);
    return sfFloatRect_contains(&bound, coord.x, coord.y);
}

void manage_mouse_release(list_sprite_t **all_s)
{
    set_rect(all_s[5]->m_spt, all_s[5]->m_spt->rect.width,
        all_s[5]->m_spt->rect.height, vecti(0, 0));
}

void manage_mouse_click(sfRenderWindow *window, sfMouseButtonEvent event,
    game_source_t *g_src, int *started)
{
    list_sprite_t *new_bullet;
    sfVector2f coord = {.x = event.x, .y = event.y};
    sfVector2f centre = {.x = WD_WIDTH / 2, .y = WD_HEIGHT / 2};
    if (!is_sprite_clicked(g_src->g_spr[5]->m_spt->spr, coord)) {
        set_rect(g_src->g_spr[5]->m_spt, g_src->g_spr[5]->m_spt->rect.width,
            g_src->g_spr[5]->m_spt->rect.height, vecti(57, 0));
        new_bullet = create_sprite("sprites/bullet.png", 8, 8, g_src->g_spr[4]);
        set_sprite_p_v(new_bullet->m_spt, centre, coord, 10);
        set_rect(new_bullet->m_spt, new_bullet->m_spt->wdt,
            new_bullet->m_spt->hgt, vecti(0, 0));
        g_src->g_spr[4] = new_bullet;
        sfSound_play(g_src->g_sound[0].sound);
    }
}
