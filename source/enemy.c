/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-adrien.audiard
** File description:
** enemy.c
*/

#include "../include/my_hunter.h"

sfVector2f e_spwn_pos(void)
{
    sfVector2f pos;
    int r = rand() % 4;
    if (r < 2) {
        pos.y = rand() % WD_HEIGHT;
        if (r == 0)
            pos.x = -25;
        else
            pos.x = WD_WIDTH + 25;
    } else {
        pos.x = rand() % WD_WIDTH;
        if (r == 2)
            pos.y = -25;
        else
            pos.y = WD_HEIGHT + 25;
    }
    return pos;
}

int create_enemy(list_sprite_t **all_s, sfSprite *bullet, int started)
{
    list_sprite_t *new_enemy;
    sfVector2f centre = {.x = WD_WIDTH / 2, .y = WD_HEIGHT / 2};
    sfFloatRect wd_bound = {.left = 0, .width = WD_WIDTH,
        .top = 0, .height = WD_HEIGHT};
    if (on_sprite(wd_bound, bullet) == 0 && started == 2) {
        new_enemy = create_sprite("sprites/enemy.png", 50, 50, all_s[0]);
        set_sprite_p_v(new_enemy->m_spt, e_spwn_pos(), centre, 150);
        set_rect(new_enemy->m_spt, new_enemy->m_spt->wdt, new_enemy->m_spt->hgt,
            vecti(0, 0));
        all_s[0] = new_enemy;
        return 1;
    }
    return 0;
}

void set_enemy_speed(moving_sprite_t *spr)
{
    spr->speed = 150;
}

void check_all_enemies(sfRenderWindow *window, list_sprite_t *enemy,
    list_sprite_t **all_s)
{
    sfFloatRect ply_bd = {.top = 485, .left = 485, .height = 30, .width = 30};
    while (enemy != NULL) {
        if (on_sprite(ply_bd, enemy->m_spt->spr))
            sfRenderWindow_close(window);
        enemy = enemy->next;
    }
}
