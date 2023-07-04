/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-adrien.audiard
** File description:
** roll_sprites.c
*/

#include "../include/my_hunter.h"

list_sprite_t roll_list(list_sprite_t *begin, void (*fct)())
{
    while (begin != NULL) {
        fct(begin->m_spt);
        begin = begin->next;
    }
}

void roll_all_sprites(list_sprite_t **all_s, void (*fct)())
{
    for (int i = 0; i < NB_SPRITE; i++) {
        if (!(i == 4 && *fct == stop_if))
            roll_list(all_s[i], fct);
    }
}

void change_list_texture(list_sprite_t *bgn, char *name, int width, int height)
{
    while (bgn != NULL) {
        change_sprite_texture(bgn->m_spt, name, width, height);
        bgn = bgn->next;
    }
}

void check_all_sprite_pos(sfRenderWindow *window, game_source_t *game_src,
    int *started)
{
    int score = game_src->score;
    roll_all_sprites(game_src->g_spr, &stop_if);
    check_all_bullet(window, game_src->g_spr[4], game_src, started);
    if (score != game_src->score)
        update_score_title(window, game_src);
    if (on_screen_roll(game_src->g_spr[1]) == 0 && *started == 1) {
        start_game(game_src->g_spr);
        (*started)++;
    }
    check_all_enemies(window, game_src->g_spr[0], game_src->g_spr);
}
