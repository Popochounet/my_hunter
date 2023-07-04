/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-adrien.audiard
** File description:
** create_enemy.c
*/

#include "../include/my_hunter.h"

void change_sprite_texture(moving_sprite_t *spr_to_set, char *name, int width,
    int height)
{
    my_strcpy(spr_to_set->name, name);
    sfSprite_destroy(spr_to_set->spr);
    sfTexture_destroy(spr_to_set->tx);
    spr_to_set->spr = sfSprite_create();
    spr_to_set->tx = sfTexture_createFromFile(name, NULL);
    spr_to_set->wdt = width;
    spr_to_set->hgt = height;
    sfSprite_setTexture(spr_to_set->spr, spr_to_set->tx, sfFalse);
    set_rect(spr_to_set, width, height, vecti(0, 0));
}

void set_sprite_p_v(moving_sprite_t *spr_to_set, sfVector2f pos,
    sfVector2f go_to, int speed)
{
    spr_to_set->pos_ini.x = pos.x;
    spr_to_set->pos_ini.y = pos.y;
    spr_to_set->pos.x = pos.x;
    spr_to_set->pos.y = pos.y;
    spr_to_set->dir.x = go_to.x;
    spr_to_set->dir.y = go_to.y;
    spr_to_set->speed = speed;
    if (speed == 0)
        stop_sprite_move(spr_to_set);
    else {
        start_sprite_move(spr_to_set);
    }
}

void set_all_sprites(list_sprite_t **all_s)
{
    set_sprite_p_v(all_s[0]->m_spt, e_spwn_pos(), vectf(CTR_X, CTR_Y), 0);
    set_sprite_p_v(all_s[1]->m_spt, vectf(CTR_X, 300), vectf(CTR_X, -24), 0);
    set_sprite_p_v(all_s[2]->m_spt, vectf(300, 700), vectf(-106, 700), 0);
    set_sprite_p_v(all_s[3]->m_spt, vectf(700, 700), vectf(1103, 700), 0);
    set_sprite_p_v(all_s[5]->m_spt, vectf(CTR_X, CTR_Y),
        vectf(CTR_X, CTR_Y), 0);
}

list_sprite_t *create_sprite(char* name, int width, int height,
    list_sprite_t *next_enemy)
{
    list_sprite_t *new_sprite_list = malloc(sizeof(list_sprite_t));
    moving_sprite_t *new_sprite = malloc(sizeof(moving_sprite_t));
    my_strcpy(new_sprite->name, name);
    new_sprite->spr = sfSprite_create();
    new_sprite->tx = sfTexture_createFromFile(name, NULL);
    new_sprite->wdt = width;
    new_sprite->hgt = height;
    sfSprite_setOrigin(new_sprite->spr, vectf(width / 2, height / 2));
    sfSprite_setTexture(new_sprite->spr, new_sprite->tx, sfFalse);
    new_sprite_list->m_spt = new_sprite;
    new_sprite_list->next = next_enemy;
    return new_sprite_list;
}

list_sprite_t **create_all_sprites(void)
{
    list_sprite_t **all_sprites = malloc(sizeof(list_sprite_t) * NB_SPRITE);
    all_sprites[0] = create_sprite("sprites/enemy.png", 50, 50, NULL);
    all_sprites[1] = create_sprite("sprites/start.png", 256, 46, NULL);
    all_sprites[2] = create_sprite("sprites/info.png", 212, 46, NULL);
    all_sprites[3] = create_sprite("sprites/exit.png", 207, 46, NULL);
    all_sprites[4] = NULL;
    all_sprites[5] = create_sprite("sprites/player.png", 114, 37, NULL);
    set_all_sprites(all_sprites);
    set_all_rect(all_sprites);
    return all_sprites;
}
